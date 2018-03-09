/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 20:40:57 by pstringe          #+#    #+#             */
/*   Updated: 2018/03/08 20:53:03 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

/*
**	multiplies a vector by a matrix
*/

void	multvect(t_3d *dst, int	mat[4][4], t_3d *src)
{
	dst->x = src->x * mat[0][0]	+ src->y * mat[1][0] + src->z * mat[2][0] + mat[3][0];
	dst->y = src->x * mat[0][1] + src->y * mat[1][1] + src->z * mat[2][1] + mat[3][1];
	dst->z = src->x * mat[0][2]	+ src->y * mat[1][2] + src->z * mat[2][2] + mat[3][2];
}

/*
**	multiplies 2 4 by 4 matricies, stores result in a destination matrix
*/

void 	matmult(int	dst[4][4], int mat[4][4], by[4][4])
{
	int	i;
	int j;
	int	k;
	int s;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			s = 0;
			k = -1;
			while (++k < 4)
			{
				s += s + mat[i][k] * by[k][j];
			}
		}
	}
}
/*
**	copies a matrix
*/

void	matcpy(int dst[4][4], int src[4][4])
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			dst[i][j] = src[i][j];
		}
	}
}

/*
**	test function to see if all the other shit works
*/

void	test(void *m, void *wn, t_list *map, int w, int h)
{
	t_img 	*img;
	t_list	*proj;

	img = new_img(m, w, h);
	printf("in test(), img->data = %p\n", img->data);
	proj = ft_lstmap(map, ortho);
	put_verts(img, proj, 0x00FF0000);
	draw_lines(img, proj, 0x00FF0000);
	mlx_put_image_to_window(m, wn, img->pntr, w, h);
}

int		main(int argc, char **argv)
{
	void	*mlx;
	void	*window;
	t_list	*map;
	int		fd;

	if (argc > 2)
		return (1);
	else if (argc < 2)
		fd = 0;
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (0);
	map = NULL;
	read_map(fd, &map);
	if (!map)
		return (0);
	print_map_data(map);
	mlx = mlx_init();
	window = mlx_new_window(mlx, 1000, 1000, "FDF");
	test(mlx, window, map, 500, 500);
	mlx_loop(mlx);
	return (0);
}
