/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 20:40:57 by pstringe          #+#    #+#             */
/*   Updated: 2018/03/08 10:55:16 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

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
**	returns a 2d vector given coordinates
*/

t_2d	*getvect2(int x, int y)
{
	t_2d	*pnt;

	if(!(pnt = ft_memalloc(sizeof(t_3d))))
		return(NULL);
	pnt->x = x;
	pnt->y = y;
	return (pnt);
}

/*
**	quick orthographic projection function to test the above function
**	(this is not the projection function I will be using)
*/

t_list	*ortho(t_list *a)
{
	t_list 	*v;
	int		sx;
	int		sz;
	int 	cx;
	int		cz;
	
	sx = 10;
	sz = 10;
	cx = 200;
	cz = 200;

	if ((v= ft_memalloc(sizeof(t_list))))
	{
		/*
		v->content_size = sizeof(t_2d*);
		((t_2d*)(v->content))->x = sx * ((t_3d*)(a->content))->x + cx;
		((t_2d*)(v->content))->y = sz * ((t_3d*)(a->content))->z + cz;
		*/
		v->content = getvect2((sx * ((t_3d*)(a->content))->x + cx),
					(sz * ((t_3d*)(a->content))->z + cz));
	}
	return (v);
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
