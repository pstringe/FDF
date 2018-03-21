/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:20:54 by pstringe          #+#    #+#             */
/*   Updated: 2018/03/21 13:21:22 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
