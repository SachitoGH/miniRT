/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:27:29 by dzapata           #+#    #+#             */
/*   Updated: 2025/04/21 23:38:26 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft_extra.h"

int	ft_atoi2(const char *nptr, int *err)
{
	int		i;
	int		number;
	char	sign;

	i = 0;
	sign = '+';
	number = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		sign = nptr[i++];
	while (ft_isdigit(nptr[i]) && number > -1)
		number = (number * 10) + (nptr[i++] - '0');
	if (number < 0)
	{
		*err = 1;
		if (sign == '-')
			return (INT_MIN);
		return (INT_MAX);
	}
	*err = 0;
	if (sign == '-')
		return (-number);
	return (number);
}
