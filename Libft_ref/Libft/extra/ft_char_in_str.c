/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_in_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 02:58:35 by dzapata           #+#    #+#             */
/*   Updated: 2024/05/27 02:59:16 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft_extra.h"

int	ft_char_in_str(char const *s1, char c)
{
	int	i;

	if (!s1)
		return (-1);
	i = -1;
	while (s1[++i])
		if (s1[i] == c)
			return (1);
	return (0);
}
