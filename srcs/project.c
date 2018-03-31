/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 11:42:09 by pstringe          #+#    #+#             */
/*   Updated: 2018/03/31 14:42:57 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	quick orthographic projection function to test the above function
**	(this is not the projection function I will be using)
*/

t_2d 	*ortho(t_3d	*a)
{
	t_2d 	*v;
	int		sx;
	int		sz;
	int 	cx;
	int		cz;
	
	sx = 10;
	sz = 10;
	cx = 0;
	cz = 0;

	if ((v = ft_memalloc(sizeof(t_2d))))
	{
		v = getvect2((sx * a->x + cx),
					(sz * a->z + cz), a);
	}
	return (v);
}

/*
**	applies orthographic projection to the whole of a map
*/

t_2d	***project(t_map *map, t_2d *(*f)(t_3d*))
{
	t_3d 	***m;
	t_2d 	***p;
	int		i;
	int		j;

	m = map->vects;
	p = (t_2d***)ft_memalloc(sizeof(t_2d**) * map->y_max + 1);
	p[map->y_max] = NULL;
	i = -1;
	while (m[++i])
	{
		p[i] = (t_2d**)ft_memalloc(sizeof(t_2d*) * map->x_max + 1);
		p[i][map->x_max] = NULL;
		j = -1;
		while (m[i][++j])
		{
			p[i][j] = f(m[i][j]);
		}
	}
	return (p);
}
