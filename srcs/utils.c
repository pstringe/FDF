/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:34:42 by pstringe          #+#    #+#             */
/*   Updated: 2018/03/06 15:42:20 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

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
