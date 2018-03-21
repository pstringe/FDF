/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:34:42 by pstringe          #+#    #+#             */
/*   Updated: 2018/03/21 13:18:11 by pstringe         ###   ########.fr       */
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

void	print_point(t_list *pnt)
{
	t_3d	*vect;

	vect = (t_3d*)(pnt->content);
	ft_putendl(ft_itoa(vect->x));
	ft_putendl(ft_itoa(vect->y));
	ft_putendl(ft_itoa(vect->z));
	ft_putendl("");
}

/*
**	utilitty function to display map data
*/

void	print_map_data(t_list *map)
{	
	t_list *tmp;

	tmp = map;
	while (tmp)
	{
		print_point(tmp);
		tmp = tmp->next;
	}
}
