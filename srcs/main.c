/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 20:40:57 by pstringe          #+#    #+#             */
/*   Updated: 2018/03/31 14:21:09 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

void	render(t_mlx *mlx, char *str)
{
	mlx->img = new_img(mlx->pntr, 500, 500);
	mlx->map->proj = project(mlx->map, ortho);
	put_verts(mlx->img, mlx->map, 0x00FF0000);
	mlx->wnd = put_img(mlx->pntr, mlx->img, str);
}
int		main(int argc, char **argv)
{
	t_mlx	*mlx;
	int		fd;

	if (argc > 2)
		return (1);
	else if (argc < 2)
		fd = 0;
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (0);
	mlx = init(fd);
	if (!mlx->map)
		return (0);
	print_map_data(mlx->map);
	render(mlx, argv[1]);
	mlx_loop(mlx->pntr);
	return (0);
}
