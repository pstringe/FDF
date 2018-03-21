/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:13:10 by pstringe          #+#    #+#             */
/*   Updated: 2018/03/21 13:16:54 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
