/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:54:15 by pstringe          #+#    #+#             */
/*   Updated: 2018/03/21 13:23:01 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

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
