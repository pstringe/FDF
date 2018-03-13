/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 20:40:57 by pstringe          #+#    #+#             */
/*   Updated: 2018/03/13 11:19:28 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

/*
**	multiplies 2 4 by 4 matricies, stores result in a destination matrix
*/

void 	matmult(int	dst[4][4], int mat[4][4], int by[4][4])
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
				s += mat[i][k] * by[k][j];
			dst[i][j] = s;
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
			dst[i][j] = src[i][j];
	}
}

/*
**	sets the value of every index within a 4*4 matrix to the integer value, n
*/

void	matset(int mat[4][4], int n)
{
	int		i;
	int		j;
	
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			mat[i][j] = n;
	}
}

/*
**	utility function to print the values within a 4 * 4 matrix
*/

void	matprnt(int mat[4][4])
{
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			ft_putchar('[');
			ft_putstr(ft_itoa(mat[i][j]));
			ft_putstr("],\t");
		}
		ft_putchar('\n');
	}
	ft_putchar('\n');
}
/*
**	a function to initialize an identity matrix
*/

void	identmat(int mat[4][4])
{
	int		i;
	int		k;

	k = 0;
	i = -1;
	matset(mat, 0);
	while (++i < 4)
	{
		mat[i][k] = 1;
		k++;
	}
}

/*
**	initializes  a scale transformation matrix
*/

void	tranmat(int mat[4][4], int x, int y, int z)
{
	identmat(mat);
	mat[3][0] = x;
	mat[3][1] = y;
	mat[3][2] = z;
	mat[3][3] = 1;
}

/*
**	applies a tansformation to a vector
*/

t_list	*transform(int mat[4][4], t_list *lst)
{
	t_list		*trans;
	t_3d		*src;
	t_3d		*dst;

	src = (t_3d*)(lst->content);
	dst = ft_memalloc(sizeof(t_3d));
	dst->x = src->x * mat[0][0]	+ src->y * mat[1][0] + src->z * mat[2][0] + mat[3][0];
	dst->y = src->x * mat[0][1] + src->y * mat[1][1] + src->z * mat[2][1] + mat[3][1];
	dst->z = src->x * mat[0][2]	+ src->y * mat[1][2] + src->z * mat[2][2] + mat[3][2];
	trans = ft_lstnew(dst, sizeof(t_3d));
	return (trans);
}

/*
**	translates a list of 3D vectors
*/

t_list *translate(t_list *src, int x, int y, int z)
{
	int		mat[4][4];
	t_list	*tran;
	t_list	*vect;
	t_list	*tmp;
	
	tran = NULL;
	tranmat(mat, x, y, z);
	tmp = src;
	while (tmp)
	{
		ft_lstadd_tail(&tran, (vect = transform(mat, tmp)));
		tmp = tmp->next;
	}
	return (tran);
}

/*
**	a test function for matcpy
*/

void	matcpy_test()
{
	int		src[4][4];
	int		dst[4][4];

	matset(src, 1);
	matset(dst, 0);
	ft_putendl("BEFORE");
	ft_putendl("src:");
	matprnt(src);
	ft_putendl("dst:");
	matprnt(dst);

	matcpy(dst, src);

	ft_putendl("AFTER");
	ft_putendl("src:");
	matprnt(src);
	ft_putendl("dst:");
	matprnt(dst);
	ft_putendl("-------------");
}

/*
**	test function for matmult
*/

void	matmult_test()
{
	int		mat[4][4];
	int		by[4][4];
	int		p[4][4];

	matset(mat, 2);
	identmat(by);
	matset(p, 0);
	ft_putendl("BEFORE");
	ft_putendl("mat:");
	matprnt(mat);
	ft_putendl("by:");
	matprnt(by);
	ft_putendl("p:");
	matprnt(p);

	matmult(p, mat, by);
	
	ft_putendl("AFTER");
	ft_putendl("mat:");
	matprnt(mat);
	ft_putendl("by:");
	matprnt(by);
	ft_putchar('\n');
	ft_putendl("p:");
	matprnt(p);
	ft_putendl("------------");
}

/*
**	test function for matscale
*/

void 	matscale_test(void *m, int w, int h, t_list *map)
{
	void	*wn1;
	void 	*wn2;
	t_img 	*img1;
	t_img	*img2;
	t_list	*trans;
	t_list	*proj1;
	t_list 	*proj2;

	wn1 = mlx_new_window(m, w, h, "ORIGINAL MAP");
	wn2 = mlx_new_window(m, (w * 2), (h * 2), "TRANFORMED MAP");

	img1 = new_img(m, w, h);
	img2 = new_img(m, w * 2, h * 2);

	trans = translate(map, 10, 10, -5);
	proj1 = ft_lstmap(map, ortho);
	proj2 = ft_lstmap(trans, ortho);

	put_verts(img1, proj1, 0x00FF0000);
	put_verts(img2, proj2, 0x00FF0000);

	mlx_put_image_to_window(m, wn1, img1->pntr, 0, 0);
	mlx_put_image_to_window(m, wn2, img2->pntr, 0, 0);
}

/*
**	test function to see if my image functions work
*/

void	img_test1(void *m, void *wn, t_list *map, int w, int h)
{
	t_img 	*img;
	t_list	*proj;

	img = new_img(m, w, h);
	printf("in test(), img->data = %p\n", img->data);
	proj = ft_lstmap(map, ortho);
	put_verts(img, proj, 0x00FF0000);
	//draw_lines(img, proj, 0x00FF0000);
	mlx_put_image_to_window(m, wn, img->pntr, w, h);
}

int		main(int argc, char **argv)
{
	void	*mlx;
	//void	*window;
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
	//matcpy_test();
	//matmult_test();
	//print_map_data(map);
	mlx = mlx_init();
	matscale_test(mlx, 500, 500, map);
	//window = mlx_new_window(mlx, 1000, 1000, "FDF");
	//img_test1(mlx, window, map, 500, 500);
	mlx_loop(mlx);
	return (0);
}
