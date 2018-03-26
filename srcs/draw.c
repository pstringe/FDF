/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 10:31:00 by pstringe          #+#    #+#             */
/*   Updated: 2018/03/26 10:32:56 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define DX (pnt2->x - pnt1->x)
#define	DY (pnt2->y - pnt1->y)

/*
**	line drwing funtion, the deltas are required to decide upon the driving axis,
**	I would calculate the within the function, the norme would require me to get rid 
**	of my df var making this a lot more cluttered. Passing in the deltas does not increase
**	the complexity, I may just use a macro for that later.
*/	

void	draw_line(t_img *img, t_2d *pnt1, t_2d *pnt2)
{
	int		da;
	int		pa;
	int		e;
	int		df;
	
	da = (df = (ft_absval(DX) >= ft_absval(DY)) ? pnt1->x : pnt1->y);
	pa = (df) ? pnt1->y : pnt1->x;
	e = (df) ? DY - DX : DX - DY;
	while (da < ((df) ? pnt2->x: pnt2->y))
	{
		set_pixel(img, ((df) ? da : pa), ((df) ? pa : da), 0x00FF0000);
		if (e >= 0)
		{
			pa++;
			e -= (df) ? DX : DY;
		}
		da++;
		e += (df) ? DX : DY;
	}
}
