/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:33:05 by pstringe          #+#    #+#             */
/*   Updated: 2018/03/07 18:29:37 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

/*
** returns a 3d vector given coordinates
*/

static t_3d	*getvect(int x, int y, int z)
{
	t_3d	*pnt;
	
	if(!(pnt = ft_memalloc(sizeof(t_3d))))
		return (NULL);
	pnt->x = x;
	pnt->y = y;
	pnt->z = z;
	return (pnt);
}

/*
** gets a row's worth of vectors
*/

static void	getvects(t_list ***map, char *row, int y, int *n)
{
	int		x;
	int		z;
	t_list	*pnt;
	t_3d	*vect;
	char	**cols;
	
	cols = ft_strsplit(row, ' ');
	x = -1;
	while (cols[++x])
	{
		z = ft_atoi(cols[x]);
		vect = getvect(x, y, z);
		pnt = ft_lstnew(vect, sizeof(t_3d));
		ft_lstadd_tail(*map, pnt);
		*n = *n + 1;
	}
}

/*
** reads map data from file
*/

void	read_map(int fd, t_list **map)
{
	int		i;
	int		j;
	int		k;
	char 	*row;
	
	i = 0;
	j = 0;
	k = 0;
	while (get_next_line(fd, &row) > 0)
	{
		getvects(&map, row, i, &k);
		i++;
	}
}


