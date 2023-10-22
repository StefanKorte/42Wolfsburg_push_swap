/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort_helpers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorte <skorte@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 07:49:02 by skorte            #+#    #+#             */
/*   Updated: 2022/03/23 08:34:40 by skorte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
// ft_is_sorted returns:
//  0, if the list is sorted,
// -1, if not sorted
*/

int	ft_is_sorted(t_list *list)
{
	int	i;
	int	a;
	int	b;

	i = 0;
	while (i < list->fill - 1)
	{
		a = list->element[ft_list_index(i, list)];
		b = list->element[ft_list_index(i + 1, list)];
		if (a > b)
			return (0);
		i++;
	}
	return (1);
}

int	ft_list_is_rot_sorted(t_list *list)
{
	int	i;
	int	out;

	i = 0;
	out = 0;
	while (i < list->fill)
	{
		if (ft_is_sorted(list))
			out = 1;
		ft_rotate(list);
		i++;
	}
	return (out);
}

void	ft_list_rot_sort(t_list *list)
{
	while (list->element[ft_list_index(list->fill - 1, list)]
		< list->element[ft_list_index(0, list)])
	{
		if (list->element[ft_list_index(0, list)] * 2 >= list->fill)
			ft_rx(list);
		else
			ft_rrx(list);
	}
	return ;
}
