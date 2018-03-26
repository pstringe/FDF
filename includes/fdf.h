/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 08:39:07 by pstringe          #+#    #+#             */
/*   Updated: 2018/03/24 15:59:45 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"
# include <stdio.h>

/*
** points in space
*/

typedef struct	s_3d
{
	int		x;
	int		y;
	int		z;
}				t_3d;

typedef struct	s_2d
{
	t_3d	*o;
	int		x;
	int		y;
}				t_2d;
	
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

void			read_map(int fd, t_list **map);

/*
** utility functions
*/

void			print_point(t_list *pnt);
void			print_map_data(t_list *map);
void			matprnt(int mat[4][4]);

/*
**	functions for dealing with vectors
*/


t_3d			*getvect(int x, int y, int z);
t_2d			*getvect2(int x, int y, t_3d *o);

/*
**	matrix initialisations
*/

void			identmat(int mat[4][4]);
void			tranmat(int mat[4][4], int x, int y, int z);

/*
**	matrix operations
*/

void			matset(int mat[4][4], int n);
void 			matmult(int	dst[4][4], int mat[4][4], int by[4][4]);
void			matcpy(int dst[4][4], int src[4][4]);

/*
**	projection functions
*/

t_list			*ortho(t_list *a);

/*
**	functions for dealing with images
*/

t_img			*new_img(void *m, int w, int h);
void			set_pixel(t_img *img, int x, int y, int v);
void			put_verts(t_img *img, t_list *vects, int v);
void 			*put_img(void *mlx, t_img *img, char *title);

/*
**	transformations
*/

t_list			*transform(int mat[4][4], t_list *lst);
t_list			*translate(t_list *src, int x, int y, int z);

/*
**	test functions
*/

void			matcpy_test();
void			matmult_test();
void			*mattran_test();
void			img_test1();
#endif
