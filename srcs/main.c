/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 20:40:57 by pstringe          #+#    #+#             */
/*   Updated: 2018/03/30 19:46:31 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

t_mlx	*init()
{
	t_mlx *mlx;

	mlx = (t_mlx*)ft_memalloc(sizeof(t_mlx));
	mlx->pntr = mlx_init();
	mlx->map = read_map(fd);
	mlx->img = NULL;
	mlx->wndw = NULL;
	return (mlx);
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;
	int		fd;
	//t_aram	p;

	if (argc > 2)
		return (1);
	else if (argc < 2)
		fd = 0;
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (0);
	mlx = init(fd);
	if (!mlx->map)
		return (0);
	mlx_loop(mlx->mlx);
	return (0);
}
