/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_minmax.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorte <skorte@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:25:25 by skorte            #+#    #+#             */
/*   Updated: 2022/03/23 08:25:52 by skorte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Functions to find the max/min value and their indexes in a stack.
*/

int	ft_max(t_list *list)
{
	int	i;
	int	max;

	i = 0;
	max = list->element[ft_list_index(0, list)];
	while (i < list->fill)
	{
		if (max < list->element[ft_list_index(i, list)])
			max = list->element[ft_list_index(i, list)];
		i++;
	}
	return (max);
}

int	ft_max_pos(t_list *list)
{
	int	i;
	int	max;
	int	pos;

	i = 0;
	pos = 0;
	max = list->element[ft_list_index(0, list)];
	while (i < list->fill)
	{
		if (max < list->element[ft_list_index(i, list)])
		{
			max = list->element[ft_list_index(i, list)];
			pos = i;
		}
		i++;
	}
	return (pos);
}

int	ft_min(t_list *list)
{
	int	i;
	int	min;

	i = 0;
	min = list->element[ft_list_index(0, list)];
	while (i < list->fill)
	{
		if (min > list->element[ft_list_index(i, list)])
			min = list->element[ft_list_index(i, list)];
		i++;
	}
	return (min);
}

int	ft_min_pos(t_list *list)
{
	int	i;
	int	min;
	int	pos;

	i = 0;
	pos = 0;
	min = list->element[ft_list_index(0, list)];
	while (i < list->fill)
	{
		if (min > list->element[ft_list_index(i, list)])
		{
			min = list->element[ft_list_index(i, list)];
			pos = i;
		}
		i++;
	}
	return (pos);
}
