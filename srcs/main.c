/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 20:40:57 by pstringe          #+#    #+#             */
/*   Updated: 2018/03/24 15:33:09 by pstringe         ###   ########.fr       */
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

/*
**	line drwing funtion, the deltas are required to decide upon the driving axis,
**	I would calculate the within the function, the norme would require me to get rid 
**	of my df var making this a lot more cluttered. Passing in the deltas does not increase
**	the complexity, I may just use a macro for that later.
*/	

void	draw_line(t_img *img, t_2d *pnt1, t_2d *pnt2, int dx, int dy)
{
	int		da;
	int		pa;
	int		e;
	int		df;
	
	da = (df = (ft_absval(dx) >= ft_absval(dy)) ? pnt1->x : pnt1->y);
	pa = (df) ? pnt1->y : pnt1->x;
	e = (df) ? dy - dx : dx - dy;
	while (da < (df) ? pnt2->x: pnt2->y)
	{
		set_pixel(img, ((df) ? da : pa), ((df) ? pa : da), 0x00FF0000);
		if (e >= 0)
		{
			pa++;
			e -= (df) ? dx : dy;
		}
		da++;
		e += (df) ? dy : dx;
	}
}

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
	wnd = mattran_test(mlx, 500, 500, map);
	//mlx_mouse_hook(wnd, mouse_hook, &p);
	//mlx_key_hook(wnd, key_hook, &p);
	//window = mlx_new_window(mlx, 1000, 1000, "FDF");
	//img_test1(mlx, window, map, 500, 500);
	mlx_loop(mlx);
	return (0);
}
