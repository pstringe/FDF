/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 11:37:53 by pstringe          #+#    #+#             */
/*   Updated: 2018/03/31 14:31:07 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*

**	a test function for matcpy

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
*/
/*
**	test function for matmult
*/
/*
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
*/
/*
**	test function for matscale


void	*mattran_test(void *m, int w, int h, t_list *map)
{
	void	*wn1;
	//void 	*wn2;
	t_img 	*img1;
	//t_img	*img2;
	//t_list*trans;
	t_list	*proj1;
	//t_list 	*proj2;

	img1 = new_img(m, w, h);
	//img2 = new_img(m, w * 2, h * 2);

	//trans = translate(map, 10, 10, -5);
	proj1 = ft_lstmap(map, ortho);
	//proj2 = ft_lstmap(trans, ortho);

	put_verts(img1, proj1, 0x00FF0000);
	//put_verts(img2, proj2, 0x00FF0000);

	wn1 = put_img(m, img1, "ORIGINAL");
	//wn2 = put_img(m, img2, "TRANSFORMED");

	printf("ORIGINAL:\t[%p]\n"TRANSFORMED:\t[%p]"\n", wn1, wn2);
	return (wn1);
}
*/

/*
**	test function to see if my image functions work


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
*/
/*
**	test function to draw lines

void	*draw_line_test(void *mlx)
{
	void	*wn;
	void	*img;
	t_list 	*vects[3];

	vects[0] = ft_lstnew(getvect2(10, 10, NULL), sizeof(t_2d));
	vects[1] = ft_lstnew(getvect2(90, 90, NULL), sizeof(t_2d));
	vects[2] = NULL;

	vects[0]->next = vects[1];
	vects[1]->next = vects[2];

	img = new_img(mlx, 100, 100);
	put_verts(img, vects[0], 0x00FF0000);
	draw_line(img, (t_2d*)(vects[0]->content), (t_2d*)(vects[1]->content));
	wn = put_img(mlx, img, "DRAW_LINE_TEST");
	return (wn);
}
*/
