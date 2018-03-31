/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 11:35:23 by pstringe          #+#    #+#             */
/*   Updated: 2018/03/31 14:56:22 by pstringe         ###   ########.fr       */
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

void	put_verts(t_img *img, t_map *map, int v)
{
	t_2d	***vects;
	int		i;
	int		j;

	vects = map->proj;
	i = -1;
	while (vects[++i])
	{
		j = -1;
		while (vects[i][++j])
		{
			set_pixel(img, (vects[i][j])->x, (vects[i][j])->y, v);
		}
	}
	/*
	 t_2d	*tmpv;

	tmp = vects;
	while (tmp)
	{
		tmpv = (t_2d*)(tmp->content);
		set_pixel(img, tmpv->x, tmpv->y, v);
		tmp = tmp->next;
	}
	*/
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

t_wnd	*put_img(void *mlx, t_img *img, char *title)
{
	t_wnd	*wn;

	wn = (t_wnd*)ft_memalloc(sizeof(t_wnd));
	wn->pntr = mlx_new_window(mlx, img->width, img->height, title);
	wn->width = img->width + 20;
	wn->height = img->height + 20;
	mlx_put_image_to_window(mlx, wn->pntr, img->pntr, 10, 10);
	return (wn);
}
