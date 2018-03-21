/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 11:35:23 by pstringe          #+#    #+#             */
/*   Updated: 2018/03/21 13:47:50 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

/*
**	edits the color of a pixel within an image
*/

void	set_pixel(t_img *img, int x, int y, int v)
{
	int		p;
	int		*data = (int*)img->data;	
	p = img->pixel;
	data[img->width * y + x] = v;
}

/*
**	uses a list of 2d vects to create a monochromatic image
*/

void	put_verts(t_img *img, t_list *vects, int v)
{
	t_list	*tmp;
	t_2d	*tmpv;

	tmp = vects;
	while (tmp)
	{
		tmpv = (t_2d*)(tmp->content);
		set_pixel(img, tmpv->x, tmpv->y, v);
		tmp = tmp->next;
	}
}

/*
**	creates new image
*/

t_img	*new_img(void *m, int w, int h)
{
	t_img	*img;
	int		l;
	int		bits;
	int 	e;

	bits = 4 * 8;
	l = 4 * w;
	e = 1;
	if(!(img = ft_memalloc(sizeof(t_img))))
		return(NULL);
	if (!(img->pntr = mlx_new_image(m, w, h)))
		return (NULL);
	if (!(img->data = mlx_get_data_addr(img->pntr, &bits, &l, &e)))
		return (NULL);
	printf("img->data = %p\n", img->data);
	img->width = w;
	img->height = h;
	img->l_size = l;
	img->pixel = bits / 8;
	return (img);
}

/*
**	creates a new window, sizes it based on the size of and image
**	and dumps the image to the window.
*/

void	*put_img(void *mlx, t_img *img, char *title)
{
	void	*wn;

	wn = mlx_new_window(mlx, img->width, img->height, title);
	mlx_put_image_to_window(mlx, wn, img->pntr, 0, 0);
	return (wn);
}
