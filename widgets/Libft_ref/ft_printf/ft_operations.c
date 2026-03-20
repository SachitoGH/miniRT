/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:58:27 by dzapata           #+#    #+#             */
/*   Updated: 2024/04/13 16:07:38 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_hex_digit_lower(int n)
{
	if (n >= 0 && n < 10)
		return (n + '0');
	else
		return (n + 'a' - 10);
}

char	ft_hex_digit_upper(int n)
{
	if (n >= 0 && n < 10)
		return (n + '0');
	else
		return (n + 'A' - 10);
}
