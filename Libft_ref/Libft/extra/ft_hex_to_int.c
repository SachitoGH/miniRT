/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:29:40 by dzapata           #+#    #+#             */
/*   Updated: 2024/08/01 02:57:44 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft_extra.h"

int	ft_islowercase(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	ft_isuppercase(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	hex_to_int(char *str)
{
	int	i;
	int	number;
	int	digit;

	if (!str)
		return (0);
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		i = 1;
	else
		i = -1;
	number = 0;
	while (str[++i])
	{
		if (ft_isdigit(str[i]))
			digit = str[i] - '0';
		else if (ft_islowercase(str[i]) && str[i] < 'g')
			digit = str[i] - 'a' + 10;
		else if (ft_isuppercase(str[i]) && str[i] < 'G')
			digit = str[i] - 'A' + 10;
		else
			break ;
		number = (number << 4) | (digit & 0xF);
	}
	return (number);
}
