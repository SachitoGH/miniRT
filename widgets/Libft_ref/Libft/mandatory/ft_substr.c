/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:38:57 by dzapata           #+#    #+#             */
/*   Updated: 2024/04/14 14:03:20 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h" 

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	lensub;
	size_t	i;
	size_t	j;
	char	*str;

	str = NULL;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	lensub = ft_strlen(&(s[start]));
	if (lensub > len)
		lensub = len;
	str = (char *) malloc(lensub + 1);
	if (!str)
		return (NULL);
	i = start;
	j = 0;
	while (s[i] && j < lensub)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
