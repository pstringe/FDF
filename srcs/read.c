/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:33:05 by pstringe          #+#    #+#             */
/*   Updated: 2018/03/26 12:21:12 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

/*
**	new list function to grab the last element of a list
*/

t_list	*ft_lstlast(t_list **lst)
{
	t_list 	*tmp;

	if(!*lst)
		return(NULL);
	tmp = *lst;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

/*
**	gets a row's worth of vectors
*/

static void	getvects(t_list ***map, t_3d *prev[4096], char *row, int y, int *n)
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
		prev[x] = (vect = getvect(x, y, z, ((x) ? (ft_lstlast(*map))->content : NULL ), prev[x]));
		pnt = ft_lstnew(vect, sizeof(t_3d));
		ft_lstadd_tail(*map, pnt);
		*n = *n + 1;
	}
}

/*
**	reads map data from file
*/

void	read_map(int fd, t_list **map)
{
	int			i;
	int			j;
	int			k;
	static t_3d	*prev[4096];
	char 		*row;
	
	i = 0;
	j = 0;
	k = 0;
	while (get_next_line(fd, &row) > 0)
	{
		getvects(&map, prev, row, i, &k);
		i++;
	}
}


