/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:43:27 by dzapata           #+#    #+#             */
/*   Updated: 2024/04/12 16:59:31 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h" 

static void	mini_itoa(int n, int fd)
{
	int		i;
	char	nbr[10];

	i = 9;
	while (n > 10)
	{
		nbr[i--] = ((n % 10) + '0');
		n /= 10;
	}
	nbr[i--] = (n + '0');
	while (nbr[++i])
		ft_putchar_fd(nbr[i], fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	mini_itoa(n, fd);
}
