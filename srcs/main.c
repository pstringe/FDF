/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 20:40:57 by pstringe          #+#    #+#             */
/*   Updated: 2018/03/26 10:33:52 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

/*
typedef struct		s_aram
{
}					t_aram;
*/
/*
**	mouse event experiment to learn the behavior of mlx_mouse_hook
*/
/*
int		mouse_hook(int button, int x, int y, void *param)
{
	printf("MOUSE EVENT:\nbutton:\t[%d]\nx:\t[%d]\ny:\t[%d]\nparam:\t[%p]\n\n", button, x, y, param);
	return (0);
}
*/
/*
**	key event
*/
/*
int		key_hook(int code, void *param)
{
	printf("KEY PRESS:\nkeycode:\t[%d]\nparam:\t[%p]\n\n", code, param);
	return (0);
}
*/

int		main(int argc, char **argv)
{
	void	*mlx;
	void	*wnd;
	t_list	*map;
	int		fd;
	//t_aram	p;

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
	//matcpy_test();
	//matmult_test();
	//print_map_data(map);
	mlx = mlx_init();
	wnd = draw_line_test(mlx);
	//wnd = mattran_test(mlx, 500, 500, map);
	//mlx_mouse_hook(wnd, mouse_hook, &p);
	//mlx_key_hook(wnd, key_hook, &p);
	//window = mlx_new_window(mlx, 1000, 1000, "FDF");
	//img_test1(mlx, window, map, 500, 500);
	mlx_loop(mlx);
	return (0);
}
