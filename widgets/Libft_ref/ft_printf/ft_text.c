/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_text.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:32:38 by dzapata           #+#    #+#             */
/*   Updated: 2024/04/15 19:15:11 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_character(const int c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_string(const char *s, int fd)
{
	size_t	i;

	if (!s)
		return (ft_string("(null)", fd));
	i = -1;
	while (s[++i])
		if (ft_character(s[i], fd) == -1)
			return (-1);
	return (i);
}
