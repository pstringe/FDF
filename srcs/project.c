/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 11:42:09 by pstringe          #+#    #+#             */
/*   Updated: 2018/03/24 16:00:00 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	quick orthographic projection function to test the above function
**	(this is not the projection function I will be using)
*/

t_list	*ortho(t_list *a)
{
	t_list 	*v;
	int		sx;
	int		sz;
	int 	cx;
	int		cz;
	
	sx = 10;
	sz = 10;
	cx = 0;
	cz = 0;

	if ((v= ft_memalloc(sizeof(t_list))))
	{
		v->content = getvect2((sx * ((t_3d*)(a->content))->x + cx),
					(sz * ((t_3d*)(a->content))->z + cz), (t_3d*)(a->content));
	}
	return (v);
}
