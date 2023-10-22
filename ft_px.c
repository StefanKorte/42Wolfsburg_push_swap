/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_px.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorte <skorte@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 13:21:37 by skorte            #+#    #+#             */
/*   Updated: 2022/02/18 13:42:14 by skorte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_list *list_1, t_list *list_2)
{
	int	temp;

	if (list_2->fill == 0)
		return ;
	else if (list_1 == list_2)
		return ;
	temp = list_2->element[list_2->first];
	list_1->element[ft_list_index(list_1->fill, list_1)] = temp;
	list_2->element[list_2->first] = 0;
	list_1->fill++;
	ft_rev_rotate(list_1);
	if (list_2->fill > 1)
		ft_rotate(list_2);
	list_2->fill--;
	return ;
}

void	ft_px(t_list *list_1, t_list *list_2)
{
	write(1, &"p", 1);
	write(1, &list_1->designation, 1);
	write(1, &"\n", 1);
	ft_push(list_1, list_2);
	return ;
}
