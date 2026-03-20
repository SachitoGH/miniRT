/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:59:34 by dzapata           #+#    #+#             */
/*   Updated: 2024/04/11 17:47:27 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h" 

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*src2;
	unsigned char		*dest2;

	if (!dest && !src)
		return (NULL);
	i = -1;
	dest2 = dest;
	src2 = src;
	if (src2 < dest2)
	{
		while ((int)--n >= 0)
			dest2[n] = src2[n];
	}
	else
	{
		while (++i < n)
			dest2[i] = src2[i];
	}
	return (dest);
}
