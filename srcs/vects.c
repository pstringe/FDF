/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vects.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 11:44:02 by pstringe          #+#    #+#             */
/*   Updated: 2018/03/26 12:23:00 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** returns a 3d vector given coordinates
*/

t_3d	*getvect(int x, int y, int z, t_3d *back, t_3d *up)
{
	t_3d	*pnt;
	
	if(!(pnt = ft_memalloc(sizeof(t_3d))))
		return (NULL);
	pnt->x = x;
	pnt->y = y;
	pnt->z = z;
	pnt->back = back;
	pnt->up = up;
	return (pnt);
}

/*
**	returns a 2d vector given coordinates
*/

t_2d	*getvect2(int x, int y, t_3d *o)
{
	t_2d	*pnt;

	if(!(pnt = ft_memalloc(sizeof(t_3d))))
		return(NULL);
	pnt->x = x;
	pnt->y = y;
	pnt->o = o;
	return (pnt);
}
