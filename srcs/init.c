/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 22:15:27 by pstringe          #+#    #+#             */
/*   Updated: 2018/03/31 14:28:13 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx	*init(int fd)
{
	t_mlx *mlx;

	mlx = (t_mlx*)ft_memalloc(sizeof(t_mlx));
	mlx->pntr = mlx_init();
	mlx->map = read_map(fd);
	mlx->img = NULL;
	mlx->wnd = NULL;
	return (mlx);
}
