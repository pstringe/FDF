/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 08:39:07 by pstringe          #+#    #+#             */
/*   Updated: 2018/03/07 13:21:28 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"

/*
** points in space
*/

typedef struct	s_2d
{
	int		x;
	int		y;
}				t_2d;

typedef struct	s_3d
{
	int		x;
	int		y;
	int		z;
}				t_3d;

/*
**	image
*/

typedef struct	s_img
{
	void	*pntr;
	char	*data;
	int		width;
	int		height;
	int		l_size;
	int		pixel;
}				t_img;

/*
** read in map vectors
*/

void	read_map(int fd, t_list **map);

/*
** utility functions
*/

void	print_point(t_list *pnt);
void	print_map_data(t_list *map);

#endif
