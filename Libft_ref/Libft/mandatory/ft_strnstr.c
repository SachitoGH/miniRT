/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:01:30 by dzapata           #+#    #+#             */
/*   Updated: 2024/04/11 20:17:43 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h" 

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = -1;
	if (s2[0] == '\0' || s1 == s2)
		return ((char *) s1);
	while (s1[++i] && i < len)
	{
		if (s1[i] == s2[0])
		{
			j = 0;
			while (s2[j] && s1[i + j] == s2[j] && (i + j) < len)
				j++;
			if (!s2[j])
				return ((char *) &s1[i]);
		}
	}
	return (NULL);
}
