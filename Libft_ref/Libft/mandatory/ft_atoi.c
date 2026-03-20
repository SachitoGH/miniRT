/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:56:29 by dzapata           #+#    #+#             */
/*   Updated: 2024/04/11 10:12:56 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h" 

int	ft_atoi(const char *nptr)
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
	while (ft_isdigit(nptr[i]))
	{
		number = (number * 10) + (nptr[i] - '0');
		i++;
	}
	if (sign == '-')
		return (-number);
	return (number);
}
