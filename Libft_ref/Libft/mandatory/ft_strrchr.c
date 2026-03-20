/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:01:49 by dzapata           #+#    #+#             */
/*   Updated: 2024/04/14 14:17:40 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h" 

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*last;
	unsigned char	uc;

	uc = (unsigned char) c;
	if (uc == '\0')
		return ((char *) &s[ft_strlen(s)]);
	i = -1;
	last = 0;
	while (s[++i])
	{
		if (s[i] == uc)
			last = (char *) &s[i];
	}
	return (last);
}
