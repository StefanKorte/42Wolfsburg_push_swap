/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorte <skorte@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:50:34 by skorte            #+#    #+#             */
/*   Updated: 2022/03/20 11:29:24 by skorte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
/*
// if called multiple times in the project, it  will not be processed again
*/
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

/*
** stdlib for malloc and free
** unistd for write
*/

/*
** The stacks are defined as a list of integers, int 'element[]'.
** To allow rotation without moving all elements, the list is seen as cyclic.
** Int 'first' gives the index of the first element.
** Int 'fill' gives the number of elements in the stack.
** Int 'length' gives the total number of elements to sort.
** Char designation will be initialized as 'a' or 'b' for stacks 'a' and 'b'.
*/

typedef struct s_list
{
	char	designation;
	int		first;
	int		fill;
	int		length;
	int		element[];
}	t_list;

// ft_atoi.c
int		ft_atoi(char *str, int *error);

//ft_list_print.c
//void	ft_list_print(t_list *list);

// ft_list_sort_helpers.c
void	ft_list_rot_sort(t_list *list);
int		ft_list_is_rot_sorted(t_list *list);

// ft_list_utils.c
int		ft_list_index(int n, t_list *list);
t_list	*ft_list_simplify(t_list *list_0);
t_list	*ft_list_init(int argc, int fill, char *argv[]);
int		ft_is_sorted(t_list *list);

// ft_push_swap_minmax.c
int		ft_max(t_list *list);
int		ft_max_pos(t_list *list);
int		ft_min(t_list *list);
int		ft_min_pos(t_list *list);

// ft_push_swap_utils.c
void	ft_sort_2(t_list *list);
void	ft_sort_3(t_list *list);

// ft_px.c
void	ft_push(t_list *list_1, t_list *list_2);
void	ft_px(t_list *list_1, t_list *list_2);

void	ft_radix_sort(t_list *list_1, t_list *list_2);
void	ft_sort_2(t_list *list);

// ft_rx.c
void	ft_rotate(t_list *list);
void	ft_rx(t_list *list);
void	ft_rev_rotate(t_list *list);
void	ft_rrx(t_list *list);

// ft_sx.c
void	ft_swap(t_list *list);
void	ft_sx(t_list *list);
void	ft_sswap(t_list *list_1, t_list *list_2);
void	ft_ss(t_list *list_1, t_list *list_2);

// ft_sort_push.c
void	ft_sort_push_out(t_list *list_1, t_list *list_2);
void	ft_sort_push_back(t_list *list_1, t_list *list_2);

#endif