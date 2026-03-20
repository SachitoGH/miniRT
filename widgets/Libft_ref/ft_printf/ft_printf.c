/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:12:39 by dzapata           #+#    #+#             */
/*   Updated: 2024/04/15 19:31:33 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	build_hex(int number, char (*digit_case)(int), int fd)
{
	t_hex	hex;

	hex.number = number;
	hex.bits = 32;
	hex.digit_case = digit_case;
	hex.prefix = 0;
	return (ft_hex(&hex, fd));
}

static int	ft_argument_manager(int fd, const char *s, va_list args)
{
	if (s[0] == '%')
		return (ft_percentage(fd));
	else if (s[0] == 'c')
		return (ft_character(va_arg(args, int), fd));
	else if (s[0] == 's')
		return (ft_string(va_arg(args, char *), fd));
	else if (s[0] == 'p')
		return (ft_pointer(va_arg(args, unsigned long), fd));
	else if (s[0] == 'x')
		return (build_hex(va_arg(args, int), ft_hex_digit_lower, fd));
	else if (s[0] == 'X')
		return (build_hex(va_arg(args, int), ft_hex_digit_upper, fd));
	else if (s[0] == 'o')
		return (ft_octal(va_arg(args, int), 0, fd));
	else if (s[0] == 'i')
		return (ft_integer(va_arg(args, int), fd));
	else if (s[0] == 'd')
		return (ft_integer(va_arg(args, int), fd));
	else if (s[0] == 'u')
		return (ft_uinteger(va_arg(args, unsigned int), fd));
	else
		return (0);
}

static int	ft_printf_funct(int fd, const char *s, va_list args)
{
	int		i;
	int		n;
	int		temp;

	i = -1;
	n = 0;
	while (s[++i])
	{
		temp = n;
		if (s[i] == '%')
			n += ft_argument_manager(fd, &s[++i], args);
		else
			n += ft_character((char)s[i], fd);
		if (n < temp)
			return (-1);
	}
	return (n);
}

int	ft_printf(const char *s, ...)
{
	int		print_c;
	va_list	args;

	va_start(args, s);
	print_c = ft_printf_funct(1, s, args);
	va_end(args);
	return (print_c);
}

int	ft_printf_fd(int fd, const char *s, ...)
{
	int		print_c;
	va_list	args;

	va_start(args, s);
	print_c = ft_printf_funct(fd, s, args);
	va_end(args);
	return (print_c);
}
