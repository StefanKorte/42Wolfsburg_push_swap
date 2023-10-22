/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorte <skorte@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:56:17 by skorte            #+#    #+#             */
/*   Updated: 2022/03/23 07:48:36 by skorte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list *list)
{
	int	a;
	int	b;

	if (list->fill < 2)
		return ;
	a = list->element[ft_list_index(0, list)];
	b = list->element[ft_list_index(1, list)];
	list->element[ft_list_index(1, list)] = a;
	list->element[ft_list_index(0, list)] = b;
	return ;
}

void	ft_sx(t_list *list)
{
	write(1, &"s", 1);
	write(1, &list->designation, 1);
	write(1, &"\n", 1);
	ft_swap(list);
	return ;
}

void	ft_sswap(t_list *list_1, t_list *list_2)
{
	ft_swap(list_1);
	ft_swap(list_2);
	return ;
}

void	ft_ss(t_list *list_1, t_list *list_2)
{
	write(1, &"ss\n", 1);
	ft_sswap(list_1, list_2);
	return ;
}
