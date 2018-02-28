/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 19:13:23 by pstringe          #+#    #+#             */
/*   Updated: 2018/02/28 08:37:02 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mlx.h"

int		main()
{
	void	*mlx;
	void	*window;
	int		w_x;
	int		w_y;
	int 	x;
	int 	y;

	w_x = 100;
	w_y = 100;
	mlx = mlx_init();
	window = mlx_new_window(mlx, w_x, w_y, "First Window");
	x = -1;
	
	while (++x < 100)
	{
		y = sin(x) - 50;
		mlx_pixel_put(mlx, window, x, y, 2234);
	}
}
