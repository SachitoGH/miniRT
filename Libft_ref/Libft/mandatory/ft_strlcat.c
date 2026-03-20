/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:00:26 by dzapata           #+#    #+#             */
/*   Updated: 2024/04/11 14:41:20 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h" 

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		j;
	int		old_size;

	if (size == 0)
		return (ft_strlen(src));
	i = -1;
	old_size = ft_strlen(dst);
	while (dst[++i] != '\0' && i < (size - 1))
	{
	}
	if (dst[i] == '\0' && i < size)
	{
		j = 0;
		while (i < size - 1 && src[j])
			dst[i++] = src[j++];
		dst[i] = '\0';
		return (old_size + ft_strlen(src));
	}
	else
		return (size + ft_strlen(src));
}
