/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 20:40:57 by pstringe          #+#    #+#             */
/*   Updated: 2018/02/28 12:31:16 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_3d	*ft_npnt3(int x, int y, int z)
{
	t_3d pnt;
	
	if (!(pnt = ft_memalloc(sizeof(t_2d))))
		return (NULL);
	pnt->x = x;
	pnt->y = y;
	pnt->z = z;
	return (pnt);
}

void	*ft_dpnt3(t_3d **pnt)
{
	*pnt->x = 0;
	*pnt->y = 0;
	*pnt->z = 0;
	ft_memdel(pnt);
}

char	*read_map(int fd)
{
	int		i;
	char	**map;
	char 	*row;
	
	i = -1;
	while (get_next_line(fd, &row) > 0)
	{
		map[i] = ft_strdup(row);
		free(row);
		i++;	
	}
	map[i] = NULL;
	return (map);
}

t_map	*parse_map(char **str)
{
	int		i;
	int		j;
	int		k;
	t_list	*map;
	t_3d	*pnt

	k = 0;
	i = -1;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			pnt = ft_npnt3(j, i, ft_atoi(str[i][j]));
			ft_lstadd_tail(&map, ft_lstnew(pnt, k));
			k++;
		}
	}
}

int		main(int argc, char **argv)
{
	void	*mlx;
	int		fd;

	if (argc > 2)
		return (1);
	else if (argc < 2)
		fd = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		return (NULL);
	parse_map(read_map(fd));

	mlx_init();
	
	mlx_loop();
	return (0);
}
