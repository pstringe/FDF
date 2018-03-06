/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 20:40:57 by pstringe          #+#    #+#             */
/*   Updated: 2018/03/05 19:21:53 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include <stdio.h>

void	ft_lstadd_tail(t_list **head, t_list *new)
{
	t_list	*tmp;

	tmp = *head;
	if (!tmp)
	{
		*head = new;
		return ;
	}
	while(tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
}

/*
** returns a 3d vector given coordinates
*/

t_3d	*getvect(int x, int y, int z)
{
	t_3d	*pnt;
	
	if(!(pnt = ft_memalloc(sizeof(t_3d))))
		return (NULL);
	pnt->x = x;
	pnt->y = y;
	pnt->z = z;
	return (pnt);
}

/*
** gets a row's worth of vectors
*/

void	getvects(t_list ***map, char *row, int y, int *n)
{
	int		x;
	int		z;
	t_list	*pnt;
	t_3d	*vect;
	char	**cols;
	
	cols = ft_strsplit(row, ' ');
	x = -1;
	while (cols[++x])
	{
		z = ft_atoi(cols[x]);
		vect = getvect(x, y, z);
		pnt = ft_lstnew(vect, sizeof(t_3d));
		ft_lstadd_tail(*map, pnt);
		*n = *n + 1;
	}
}

/*
** reads map data from file
*/

void	read_map(int fd, t_list **map)
{
	int		i;
	int		j;
	int		k;
	char 	*row;
	
	i = 0;
	j = 0;
	k = 0;
	map = NULL;
	while (get_next_line(fd, &row) > 0)
	{
		getvects(&map, row, i, &k);
		i++;
	}
}

/*
**	utility function to display the information assotiated with one 3D vector
*/

void	print_point(t_list *pnt)
{
	t_3d	*vect;

	vect = (t_3d*)(pnt->content);
	ft_putendl(ft_itoa(vect->x));
	ft_putendl(ft_itoa(vect->y));
	ft_putendl(ft_itoa(vect->z));
	ft_putendl("");
}

/*
**	utilitty function to display map data
*/

void	print_map_data(t_list *map)
{	
	t_list *tmp;

	tmp = map;
	while (tmp)
	{
		print_point(tmp);
		tmp = tmp->next;
	}
}

int		main(int argc, char **argv)
{
	//void	*mlx;
	//void	*window;
	t_list		*map;
	int		fd;

	if (argc > 2)
		return (1);
	else if (argc < 2)
		fd = 0;
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (0);
	map = NULL;
	read_map(fd, &map);
	if (!map)
		return (0);
	print_map_data(map);
	//mlx = mlx_init();
	//window = mlx_new_window(mlx, 1000, 1000, "FDF");
	//mlx_loop(mlx);
	return (0);
}
