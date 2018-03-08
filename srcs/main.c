/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 20:40:57 by pstringe          #+#    #+#             */
/*   Updated: 2018/03/08 12:30:30 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

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
