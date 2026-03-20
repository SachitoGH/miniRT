/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:39:50 by dzapata           #+#    #+#             */
/*   Updated: 2024/04/12 14:23:32 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h" 

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (ft_char_in_str(set, s1[i]))
		i++;
	start = i;
	i = ft_strlen(&s1[start]) + start - 1;
	while (ft_char_in_str(set, s1[i]) && i > start)
		i--;
	end = i;
	str = (char *) malloc(end - start + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (start <= end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
