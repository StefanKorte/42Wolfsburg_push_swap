/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorte <skorte@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 13:47:39 by skorte            #+#    #+#             */
/*   Updated: 2022/03/20 11:36:47 by skorte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Radix sort is a bucket sort algorithm with 2 stacks.
** It sorts bitwise, starting with the least significant bit.
** For each relevant bit, the entries with '0' are pushed from stack a to b.
** Therefore, stack a is rotated all the way.
** Then the elements are pushed back to stack a.
** After the most significant bit has been pushed forth and back,
** the list is sorted.
*/

/*
** ft_radix_max_bit returns the number of significant bits of a SIMPLIFIED list
*/

static int	ft_radix_find_max_bit(t_list *list)
{
	int	bit_max;

	bit_max = 0;
	while (list->length >> bit_max)
		bit_max++;
	return (bit_max);
}

/*
** ft_radix_find_end searches the last element that does not have to be pushed,
** so that pushing all following elements forth and back is superfluous and
** will be skipped.
*/

static int	ft_radix_find_end(t_list *list, int bit)
{
	int	end;

	end = list->length;
	while (end > 0)
	{
		if ((list->element[ft_list_index(end - 1, list)] >> bit) & 1)
			break ;
		end--;
	}
	return (end);
}

/*
** ft_radix_is_bit_sorted tests if a stack is already sorted regarding
** bit 'bit'.
**
** Returns '1' if sorted and '0' otherwise.
** If it is already sorted, this step for the radix sort will be skipped.
*/

static int	ft_radix_is_bit_sorted(t_list *list, int bit)
{
	int	i;

	i = list->length - 1;
	while ((list->element[ft_list_index(i, list)] >> bit) & 1)
		i--;
	while (i >= 0)
	{
		if ((list->element[ft_list_index(i, list)] >> bit) & 1)
			return (0);
		i--;
	}
	return (1);
}

void	ft_radix_sort(t_list *list_1, t_list *list_2)
{
	int	i;
	int	bit;
	int	end;

	i = 0;
	bit = 0;
	while (bit < ft_radix_find_max_bit(list_1))
	{
		if (!ft_radix_is_bit_sorted(list_1, bit))
		{
			i = 0;
			end = ft_radix_find_end(list_1, bit);
			while (i++ < end)
			{
				if (((list_1->element[list_1->first]) >> bit) & 1)
					ft_rx(list_1);
				else
					ft_px(list_2, list_1);
			}
			while (list_2->fill > 0)
				ft_px(list_1, list_2);
		}
		bit++;
	}
	return ;
}
