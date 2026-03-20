/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:59:56 by dzapata           #+#    #+#             */
/*   Updated: 2024/04/14 14:16:15 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h" 

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	unsigned char	uc;

	if (!s)
		return (NULL);
	uc = (unsigned char) c;
	if (uc == '\0')
		return ((char *) &s[ft_strlen(s)]);
	i = -1;
	while (s[++i])
	{
		if (s[i] == uc)
			return ((char *) &s[i]);
	}
	return (NULL);
}
