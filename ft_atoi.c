/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorte <skorte@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 01:18:40 by skorte           #+#    #+#             */
/*   Updated: 2021/08/21 15:53:09 by skorte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** The atoi() function converts the initial portion of the string
** pointed to by nptr to int.
** The string may begin with an arbitrary amount of white space
** followed by a single optional '+' or '-' sign.
** The remainder of the string is converted to a long value in the
** obvious manner, stopping at the first character which is not a
** valid digit.
** If the end of the string is not reached (stopped at non-numeric char)
** or the number is out of integer range, an error variable is set.
*/

static char	*ft_skip(char *nptr)
{
	while (1)
	{
		if (*nptr == ' ' || *nptr == '\t' || *nptr == '\v')
			nptr++;
		else if (*nptr == '\r' || *nptr == '\n' || *nptr == '\f')
			nptr++;
		else
			break ;
	}
	if (*nptr == '+')
		nptr++;
	return (nptr);
}

int	ft_atoi(char *nptr, int *error)
{
	long int	output_int;
	long int	sign;

	sign = 1;
	nptr = ft_skip(nptr);
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	output_int = 0;
	if (*nptr == 0)
		error[0] = 2;
	while (*nptr >= '0' && *nptr <= '9')
	{	
		output_int = output_int * 10 + *nptr - '0';
		if (sign * output_int > 2147483647 || sign * output_int < -2147483648)
			error[0] = 1;
		nptr++;
	}
	if (*nptr != 0)
		error[0] = 2;
	return ((int)(sign * output_int));
}
