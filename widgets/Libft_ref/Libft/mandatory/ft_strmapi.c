/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:41:21 by dzapata           #+#    #+#             */
/*   Updated: 2024/04/11 10:06:34 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h" 

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;
	size_t	len;

	len = ft_strlen(s);
	str = (char *) malloc(len + 1);
	if (!str)
		return (NULL);
	i = -1;
	while ((++i) < len)
		str[i] = f(i, s[i]);
	str[i] = '\0';
	return (str);
}
