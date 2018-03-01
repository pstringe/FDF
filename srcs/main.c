/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 20:40:57 by pstringe          #+#    #+#             */
/*   Updated: 2018/02/28 20:04:14 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

/*
** utility function to display contents of point struct
*/

void	ft_dispnt3(t_3d *pnt)
{
	ft_putendl(ft_itoa(pnt->x));
	ft_putendl(ft_itoa(pnt->y));
	ft_putendl(ft_itoa(pnt->z));
}

/*
** allocates a 3d point
*/

t_3d	*ft_npnt3(int x, int y, int z)
{
	t_3d *pnt;
	
	if (!(pnt = ft_memalloc(sizeof(t_2d))))
		return (NULL);
	pnt->x = x;
	pnt->y = y;
	pnt->z = z;
	return (pnt);
}

/*
** destroys a 3d point	
*/

void	ft_dpnt3(t_3d **pnt)
{
	(*pnt)->x = 0;
	(*pnt)->y = 0;
	(*pnt)->z = 0;
	ft_memdel((void **)pnt);
}

/*
** reads map data from file
*/

char	**read_map(int fd)
{
	int		i;
	char	*map;
	char 	*row;
	
	i = 0;
	while (get_next_line(fd, &row) > 0)
	{
		map = ft_strjoin(map, ft_strdup(row));
		free(row);
		i++;	
	}
	map[ft_strlen(map)] = '\0';
	return (ft_strsplit(map, '\n'));
}

/*
** creates map of 3d point structs
*/

t_map	*ft_getholo(char **str)
{
	int		i;
	int		j;
	int		k;
	t_map	*map;
	t_3d	*pnt;

	map = ft_memalloc(sizeof(t_map));
	k = 0;
	i = -1;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			pnt = ft_npnt3(j, i, (int)str[i][j]);
			ft_lstadd(&(map->holo), ft_lstnew(pnt, k));
			k++;
		}
	}
	map->size = k;
	return (map);
}

int		main(int argc, char **argv)
{
	int		x;
	int		y;
	int		z;
	int		k;

	void	*mlx;
	void	*window;
	t_map	*map;
	t_list	*tmp;
	int		fd;

	if (argc > 2)
		return (1);
	else if (argc < 2)
		fd = 0;
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (0);
	if(!(map = ft_getholo(read_map(fd))))
		return (0);
	mlx = mlx_init();
	window = mlx_new_window(mlx, 1000, 1000, "FDF");
	
	tmp = map->holo;
	k = 0;
	while (k++ < (int)(tmp->content_size))
	{
		x = ((t_3d*)(tmp->content))->x;
		y = ((t_3d*)(tmp->content))->y;
		z = ((t_3d*)(tmp->content))->z;
		mlx_pixel_put(mlx, window, x + 500 , y + 500, 0xF44242);
		tmp = tmp->next;
	}	
	mlx_loop(mlx);
	return (0);
}
