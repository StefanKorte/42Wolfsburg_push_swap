/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorte <skorte@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 13:49:26 by skorte            #+#    #+#             */
/*   Updated: 2022/03/23 08:25:07 by skorte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Since the first element of the list can be any inside the array,
** the function ft_list_index returns the index of the nth list element
*/

int	ft_list_index(int n, t_list *list)
{
	n += list->first;
	n += list->length;
	n %= list->length;
	return (n);
}

/*
** If an error occurs during list filling,
** (double element, non-numeric, out-of-range,)
** all t_lists are freed, an error written to stderr,
** and the program exits.
*/

static void	ft_error(t_list *list_1, t_list *list_2)
{
	write(STDERR_FILENO, "Error\n", 6);
	if (list_1)
		free(list_1);
	if (list_2)
		free(list_2);
	exit (-1);
}

/*
** This function translates a stack of numbers into numbers 0, 1, 2, 3, ...
** retaining the order of the elements. It returns a new t_list.
*/

t_list	*ft_list_simplify(t_list *list_0)
{
	int		i;
	int		j;
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list) + list_0->length * sizeof(int));
	list->length = list_0->length;
	list->first = 0;
	list->fill = list_0->length;
	list->designation = list_0->designation;
	i = 0;
	while (i < list_0->length)
	{
		list->element[i] = 0;
		j = 0;
		while (j < list_0->length)
		{
			if (list_0->element[i] > list_0->element[j])
				list->element[i] += 1;
			else if (list_0->element[i] == list_0->element[j] && i != j)
				ft_error(list, list_0);
			j++;
		}
		i++;
	}
	return (list);
}

/*
** This function initializes the stacks. If it is given argv[],
** it will fill the list with the arguments from command line.
*/

t_list	*ft_list_init(int argc, int fill, char *argv[])
{
	int		i;
	t_list	*list;
	int		error;

	error = 0;
	list = (t_list *)malloc(sizeof(t_list) + argc * sizeof(int));
	list->length = argc;
	list->first = 0;
	list->fill = fill;
	list->designation = 'a';
	i = 0;
	while (i++ < fill)
		list->element[i - 1] = ft_atoi(argv[i], &error);
	if (error)
		ft_error(list, NULL);
	while (i++ < argc)
	{
		list->element[i - 1] = 0;
		list->designation = 'b';
	}
	return (list);
}
