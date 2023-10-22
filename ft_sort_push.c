/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorte <skorte@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:16:56 by skorte            #+#    #+#             */
/*   Updated: 2022/03/23 08:33:35 by skorte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Functions to push elements from stack a to b,
** and to insert them back into stack a.
*/

static int	ft_find_pos(t_list *list, int element)
{
	int	pos;

	if (element < ft_min(list))
		pos = ft_min_pos(list);
	else if (element > ft_max(list))
		pos = ft_max_pos(list) + 1;
	else if (element < list->element[list->first]
		&& element > list->element[ft_list_index(list->fill - 1, list)])
		pos = 0;
	else
	{
		pos = 1;
		while (pos < list->fill)
		{
			if (element > list->element[ft_list_index(pos - 1, list)]
				&& element < list->element[ft_list_index(pos, list)])
				break ;
			pos++;
		}
	}
	return (pos);
}

/*
** Pushes elements from stack a to b until 3 elements are left.
** Prefers to push min or max, so insert will use less steps later.
*/

void	ft_sort_push_out(t_list *list_1, t_list *list_2)
{
	int	a_0;
	int	a_1;
	int	a_last;

	while (list_1->fill > 3 && !ft_list_is_rot_sorted(list_1))
	{
		a_0 = list_1->element[ft_list_index(0, list_1)];
		a_1 = list_1->element[ft_list_index(1, list_1)];
		a_last = list_1->element[ft_list_index(list_1->fill - 1, list_1)];
		if (a_0 == 0 || a_0 == list_1->length - 1)
			ft_px(list_2, list_1);
		else if (a_1 == 0 || a_1 == list_1->length - 1)
			ft_rx(list_1);
		else if (a_last == 0 || a_last == list_1->length - 1)
			ft_rrx(list_1);
		else
			ft_px(list_2, list_1);
	}
	return ;
}

/*
** Sorts elements from list b back into list a.
** Recursive, so does not rotate to beginning after last insert.
*/

void	ft_sort_push_back(t_list *list_1, t_list *list_2)
{
	int	pos;

	if (list_2->fill == 0)
		return ;
	pos = ft_find_pos(list_1, list_2->element[list_2->first]);
	if (pos * 2 < (list_1->fill))
		while (pos--)
			ft_rx(list_1);
	else
		while (pos++ < list_1->fill)
			ft_rrx(list_1);
	ft_px(list_1, list_2);
	ft_sort_push_back(list_1, list_2);
	return ;
}
