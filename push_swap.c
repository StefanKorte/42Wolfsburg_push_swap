/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorte <skorte@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:51:06 by skorte            #+#    #+#             */
/*   Updated: 2022/03/23 08:09:32 by skorte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_insert(t_list *list_1, t_list *list_2)
{
	ft_sort_push_out(list_1, list_2);
	if (list_1->fill == 3)
		ft_sort_3(list_1);
	ft_sort_push_back(list_1, list_2);
	ft_list_rot_sort(list_1);
	return ;
}

void	ft_select_sort(t_list *list_1, t_list *list_2)
{
	if (ft_is_sorted(list_1))
		return ;
	else if (list_1->fill <= 2)
		ft_sort_2(list_1);
	else if (list_1->fill == 3)
		ft_sort_3(list_1);
	else if (list_1->fill <= 50)
		ft_sort_insert(list_1, list_2);
	else if (list_1->fill > 50)
		ft_radix_sort(list_1, list_2);
	return ;
}

int	main(int argc, char *argv[])
{
	t_list	*list_0;
	t_list	*list_1;
	t_list	*list_2;

	if (!--argc)
		return (0);
	list_0 = ft_list_init(argc, argc, argv);
	list_1 = ft_list_simplify(list_0);
	list_2 = ft_list_init(argc, 0, NULL);
	ft_select_sort(list_1, list_2);
	free(list_0);
	free(list_1);
	free(list_2);
	return (0);
}
