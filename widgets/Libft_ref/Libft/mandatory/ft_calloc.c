/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:57:01 by dzapata           #+#    #+#             */
/*   Updated: 2024/04/11 20:37:42 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h" 

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*data;

	data = (char *) malloc(nmemb * size);
	if (!data)
		return (NULL);
	ft_bzero(data, nmemb * size);
	return (data);
}
