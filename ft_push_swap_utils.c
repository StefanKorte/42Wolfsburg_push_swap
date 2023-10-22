/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorte <skorte@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 07:31:27 by skorte            #+#    #+#             */
/*   Updated: 2022/03/23 08:26:39 by skorte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Sorts a stack with 2 numbers.
*/

void	ft_sort_2(t_list *list)
{
	int	a;
	int	b;

	if (list->fill < 2)
		return ;
	a = list->element[ft_list_index(0, list)];
	b = list->element[ft_list_index(1, list)];
	if (a > b)
		ft_sx(list);
	return ;
}

/*
** Sorts a stack with 3 numbers.
*/

void	ft_sort_3(t_list *list)
{
	int	a;
	int	b;
	int	c;

	a = list->element[ft_list_index(0, list)];
	b = list->element[ft_list_index(1, list)];
	c = list->element[ft_list_index(2, list)];
	if (b > a && a > c)
		ft_rrx(list);
	if (a > c && c > b)
		ft_rx(list);
	if ((c > a && a > b) || (a > b && b > c) || (b > c && c > a))
	{
		ft_sx(list);
		ft_sort_3(list);
	}
	return ;
}
