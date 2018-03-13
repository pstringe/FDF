/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 20:40:57 by pstringe          #+#    #+#             */
/*   Updated: 2018/03/13 12:09:41 by pstringe         ###   ########.fr       */
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
