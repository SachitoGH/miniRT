/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:29:10 by dzapata           #+#    #+#             */
/*   Updated: 2024/04/15 19:31:15 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_percentage(int fd)
{
	return (ft_character('%', fd));
}

int	ft_pointer(unsigned long p, int fd)
{
	t_hex	hex;

	hex.number = p;
	hex.bits = 64;
	hex.digit_case = &ft_hex_digit_lower;
	hex.prefix = 1;
	return (ft_hex(&hex, fd));
}
