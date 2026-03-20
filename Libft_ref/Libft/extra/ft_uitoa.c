/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:40:38 by dzapata           #+#    #+#             */
/*   Updated: 2024/04/13 18:18:36 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_uitoa(unsigned int number)
{
	char	*nbr;
	int		size;

	size = get_uint_size(number);
	nbr = (char *) malloc(size + 1);
	if (!nbr)
		return (NULL);
	nbr[size] = '\0';
	while ((--size) >= 0)
	{
		nbr[size] = ((number % 10) + '0');
		number /= 10;
	}
	return (nbr);
}
