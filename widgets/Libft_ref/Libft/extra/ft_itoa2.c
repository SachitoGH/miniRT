/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 23:38:41 by dzapata           #+#    #+#             */
/*   Updated: 2025/03/30 04:06:10 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft_extra.h"

void	ft_itoa2(int n, char *nbr)
{
	int		size;
	long	n_cpy;

	size = get_int_size(n);
	n_cpy = n;
	if (n < 0)
		n_cpy = -n_cpy;
	nbr[size] = '\0';
	while ((--size) >= 0 && n_cpy >= 0)
	{
		nbr[size] = ((n_cpy % 10) + '0');
		n_cpy /= 10;
	}
	if (nbr[0] == '0' && n != 0)
		nbr[0] = '-';
}
