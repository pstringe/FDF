/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vects.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 11:44:02 by pstringe          #+#    #+#             */
/*   Updated: 2018/03/08 12:04:05 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
**	returns a 2d vector given coordinates
*/

t_2d	*getvect2(int x, int y)
{
	t_2d	*pnt;

	if(!(pnt = ft_memalloc(sizeof(t_3d))))
		return(NULL);
	pnt->x = x;
	pnt->y = y;
	return (pnt);
}
