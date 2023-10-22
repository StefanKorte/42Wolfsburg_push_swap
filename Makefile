# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skorte <skorte@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 11:32:43 by skorte            #+#    #+#              #
#    Updated: 2022/03/20 11:36:27 by skorte           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC_FILE = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SOURCES = 	push_swap.c				\
			ft_px.c					\
			ft_rx.c					\
			ft_sx.c					\
			ft_atoi.c				\
			ft_list_utils.c			\
			ft_list_sort_helpers.c	\
			ft_push_swap_minmax.c	\
			ft_push_swap_utils.c	\
			ft_radix.c				\
			ft_sort_push.c			\
			
OBJECTS = $(SOURCES:.c=.o)

all: $(EXEC_FILE)

$(EXEC_FILE): $(OBJECTS)
	$(CC) $(CFLAGS)  $^ -o $@ 

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f push_swap

re: fclean all

.PHONY: all bonus push_swap clean fclean re
