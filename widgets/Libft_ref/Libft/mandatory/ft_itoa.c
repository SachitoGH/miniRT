/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:40:38 by dzapata           #+#    #+#             */
/*   Updated: 2024/04/12 13:54:03 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h" 

char	*ft_itoa(int n)
{
	char	*nbr;
	int		size;
	long	n_cpy;

	size = get_int_size(n);
	n_cpy = n;
	if (n < 0)
	{
		size++;
		n_cpy *= -1;
	}
	nbr = (char *) malloc(size + 1);
	if (!nbr)
		return (NULL);
	nbr[size] = '\0';
	while ((--size) >= 0 && n_cpy >= 0)
	{
		nbr[size] = ((n_cpy % 10) + '0');
		n_cpy /= 10;
	}
	if (nbr[0] == '0' && n != 0)
		nbr[0] = '-';
	return (nbr);
}
