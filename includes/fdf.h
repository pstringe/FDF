/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 08:39:07 by pstringe          #+#    #+#             */
/*   Updated: 2018/03/30 22:18:49 by pstringe         ###   ########.fr       */
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
**	points in space
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
**	stores map data
*/

typedef struct	s_map
{
	int				x_max;
	int				y_max;
	int				z_min;
	int				z_max;
	struct s_3d		***vects;
	struct s_2d		***proj;	
}				t_map;

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
**	this stores window information, for now I only want one window associated with each mlx pntr, 
**	but I may want more in the future
*/

typedef struct	s_wnd
{
	void	*pntr;
	void	*width;
	void	*height;
}				t_wnd;

/*
**	mlx info for now I only want one window associated with a pntr at a time
*/

typedef struct	s_mlx
{
	void	*pntr;
	t_wnd 	*wndw;
	t_img	*img;
	t_map	*map;
}				t_mlx;

/*
**	initialize all the stuff
*/

t_mlx	*init(int fd);

/*
** read in map vectors
*/

t_map			*read_map(int fd);

/*
** utility functions
*/

void			print_point(t_3d *pnt);
void			print_map_data(t_map *map);
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
**	functions for drawing on images
*/

void			draw_line(t_img *img, t_2d *pnt1, t_2d *pnt2);
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
void			*draw_line_test(void *mlx);

#endif
