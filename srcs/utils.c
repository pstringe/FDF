/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:34:42 by pstringe          #+#    #+#             */
/*   Updated: 2018/03/30 21:37:26 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

/*
**	utility function to print the values within a 4 * 4 matrix
*/

void	matprnt(int mat[4][4])
{
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			ft_putchar('[');
			ft_putstr(ft_itoa(mat[i][j]));
			ft_putstr("],\t");
		}
		ft_putchar('\n');
	}
	ft_putchar('\n');
}

/*
**	utility function to display the information assotiated with one 3D vector
*/

void	print_point(t_3d *vect)
{
	ft_putendl(ft_itoa(vect->x));
	ft_putendl(ft_itoa(vect->y));
	ft_putendl(ft_itoa(vect->z));
	ft_putendl("");
}

/*
**	utilitty function to display map data
*/

void	print_map_data(t_map *map)
{	
	int		i;
	int		j;
	t_3d	***vects;

	ft_putendl(ft_itoa(map->x_max));
	ft_putendl(ft_itoa(map->y_max));
	vects = map->vects;
	i = -1;
	while (vects[++i])
	{
		j = -1;
		while (vects[++j])
		{
			print_point(vects[i][j]);
		}
	}
}
