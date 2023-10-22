/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorte <skorte@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 13:13:50 by skorte            #+#    #+#             */
/*   Updated: 2022/03/23 08:28:11 by skorte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Rotate operator, in silent (ft_rotate) and verbose (ft_rx).
*/

void	ft_rotate(t_list *list)
{
	int	temp;

	if (list->fill < 2)
		return ;
	if (list->fill == 2)
	{
		ft_swap(list);
		return ;
	}
	if (list->fill != list->length)
	{
		temp = list->element[list->first];
		list->element[ft_list_index(list->fill, list)] = temp;
		list->element[list->first] = 0;
	}
	list->first = ft_list_index(1, list);
	return ;
}

void	ft_rx(t_list *list)
{
	if (list->fill < 2)
		return ;
	write(1, &"r", 1);
	write(1, &list->designation, 1);
	write(1, &"\n", 1);
	ft_rotate(list);
	return ;
}

/*
** Reverse rotate operator, in silent (ft_rev_rotate) and verbose (ft_rrx).
*/

void	ft_rev_rotate(t_list *list)
{
	int	temp;

	if (list->fill == 2)
	{
		ft_swap(list);
		return ;
	}
	if (list->fill != list->length)
	{
		temp = list->element[ft_list_index(list->fill - 1, list)];
		list->element[ft_list_index(list->length - 1, list)] = temp;
		list->element[ft_list_index(list->fill - 1, list)] = 0;
	}
	list->first = ft_list_index(-1, list);
	return ;
}

void	ft_rrx(t_list *list)
{
	if (list->fill < 2)
		return ;
	write(1, &"rr", 2);
	write(1, &list->designation, 1);
	write(1, &"\n", 1);
	ft_rev_rotate(list);
	return ;
}
