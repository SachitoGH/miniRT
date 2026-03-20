/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:23:23 by dzapata           #+#    #+#             */
/*   Updated: 2024/04/15 19:33:41 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(t_hex *hex, int fd)
{
	int	i;
	int	n;
	int	temp;

	n = 0;
	if (hex->prefix)
		n += ft_string("0x", fd);
	if (n == -1)
		return (-1);
	i = hex->bits - 4;
	while (((hex->number >> i) & 0xf) == 0 && i > 0)
		i -= 4;
	while (i >= 0)
	{
		temp = ft_character(hex->digit_case((hex->number >> i) & 0xf), fd);
		if (temp == -1)
			return (-1);
		n += temp;
		i -= 4;
	}
	return (n);
}

int	ft_octal(unsigned int number, int prefix, int fd)
{
	int	i;
	int	n;
	int	temp;

	n = 0;
	if (prefix)
		n = ft_character('0', fd);
	if (n == -1)
		return (-1);
	i = (sizeof(number) << 3) - 2;
	while (((number >> i) & 7) == 0 && i > 0)
		i -= 3;
	while (i >= 0)
	{
		temp = ft_character(((number >> i) & 7) + '0', fd);
		if (temp == -1)
			return (-1);
		n += temp;
		i -= 3;
	}
	return (n);
}

int	ft_integer(int number, int fd)
{
	int		size;
	char	*n;

	n = ft_itoa(number);
	if (!n)
		return (-1);
	size = ft_string(n, fd);
	free(n);
	return (size);
}

int	ft_uinteger(unsigned int number, int fd)
{
	int		size;
	char	*n;

	n = ft_uitoa(number);
	if (!n)
		return (-1);
	size = ft_string(n, fd);
	free(n);
	return (size);
}
