/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:39:26 by dzapata           #+#    #+#             */
/*   Updated: 2024/04/11 10:02:42 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h" 

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	size_t	i;
	size_t	j;
	char	*str;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *) malloc(total_len + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}
