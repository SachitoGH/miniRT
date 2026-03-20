/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 02:02:01 by dzapata           #+#    #+#             */
/*   Updated: 2024/08/01 05:40:08 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft_extra.h"

long	ft_atol(const char *nptr)
{
	int		i;
	long	number;
	char	sign;

	i = 0;
	sign = '+';
	number = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		sign = nptr[i++];
	while (ft_isdigit(nptr[i]) && number > -1)
	{
		number = (number * 10) + (nptr[i] - '0');
		i++;
	}
	if (number < 0)
	{
		if (sign == '-')
			return (LONG_MIN);
		return (LONG_MAX);
	}
	if (sign == '-')
		return (-number);
	return (number);
}
