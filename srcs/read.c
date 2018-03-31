/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:33:05 by pstringe          #+#    #+#             */
/*   Updated: 2018/03/30 21:43:59 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

/*
**	gets len of double char array;
*/
static int		ft_splitlen(char **s)
{
	int		i;
	
	i = -1;
	while (s[++i]){}
	return (i);
}

/*
** gets a row's worth of vectors
*/

static t_3d		**getvects(char *row, int y)
{
	int		x;
	int		z;
	t_3d	**vects;
	char	**cols;
	
	cols = ft_strsplit(row, ' ');
	x = -1;
	vects = ft_memalloc(sizeof(t_3d*) * ft_splitlen(cols));
	while (cols[++x])
	{
		z = ft_atoi(cols[x]);
		vects[x] = getvect(x, y, z);
	}
	vects[x] = NULL;
	return (vects);
}

/*
**	determines boundries of map data for scaling to images 
**	and windows
*/

t_map	*bind(t_map *map)
{
	int		i;
	int		j;
	int		minz;
	int		maxz;
	t_3d	*cur;

	maxz = ((map->vects)[0][0])->z;
	minz = maxz;
	i = -1;
	while ((map->vects)[++i])
	{
		j = -1;
		while ((cur = ((map->vects)[i][++j])))
		{
			maxz = (cur->z > maxz) ? cur->z: maxz;
			minz = (cur->z < minz) ? cur->z: minz;
		}
	}
	map->x_max = j;
	map->y_max = i;
	map->z_max = maxz;
	map->z_min = minz;
	return (map);
}

/*
** reads map data from file
*/

t_map	*read_map(int fd)
{
	int		i;
	char 	*row;
	t_3d	**smap[8000];
	t_map	*map;
	
	i = 0;
	while (get_next_line(fd, &row) > 0)
	{
		smap[i] = getvects(row, i);
		i++;
	}
	smap[i] = NULL;
	map = (t_map*)ft_memalloc(sizeof(t_map));
	map->vects = (t_3d***)ft_memalloc(sizeof(t_3d**) * (i + 1));
	(map->vects)[i] = NULL;
	i = -1;
	while (smap[++i])
		(map->vects)[i] = smap[i];
	return (bind(map));
}


