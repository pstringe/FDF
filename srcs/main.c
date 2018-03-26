/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 20:40:57 by pstringe          #+#    #+#             */
/*   Updated: 2018/03/26 09:51:11 by pstringe         ###   ########.fr       */
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

#define DX (pnt2->x - pnt1->x)
#define	DY (pnt2->y - pnt1->y)

void	draw_line(t_img *img, t_2d *pnt1, t_2d *pnt2)
{
	int		da;
	int		pa;
	int		e;
	int		df;
	
	da = (df = (ft_absval(DX) >= ft_absval(DY)) ? pnt1->x : pnt1->y);
	pa = (df) ? pnt1->y : pnt1->x;
	e = (df) ? DY - DX : DX - DY;
	while (da < (df) ? pnt2->x: pnt2->y)
	{
		set_pixel(img, ((df) ? da : pa), ((df) ? pa : da), 0x00FF0000);
		if (e >= 0)
		{
			pa++;
			e -= (df) ? DX : DY;
		}
		da++;
		e += (df) ? DX : DY;
	}
}
void	*draw_line_test(void *mlx)
{
	void	*wn;
	void	*img;
	t_list 	*vects[3];

	vects[0] = ft_lstnew(getvect2(10, 10, NULL), sizeof(t_2d));
	vects[1] = ft_lstnew(getvect2(90, 90, NULL), sizeof(t_2d));
	vects[2] = NULL;

	vects[0]->next = vects[1];
	vects[1]->next = vects[2];

	img = new_img(mlx, 100, 100);
	put_verts(img, vects[0], 0x00FF0000);
	wn = put_img(mlx, img, "DRAW_LINE_TEST");
	return (wn);
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
	wnd = draw_line_test(mlx);
	//wnd = mattran_test(mlx, 500, 500, map);
	//mlx_mouse_hook(wnd, mouse_hook, &p);
	//mlx_key_hook(wnd, key_hook, &p);
	//window = mlx_new_window(mlx, 1000, 1000, "FDF");
	//img_test1(mlx, window, map, 500, 500);
	mlx_loop(mlx);
	return (0);
}
