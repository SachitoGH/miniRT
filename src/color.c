/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 23:56:03 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/10 20:31:49 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

inline t_fvector3	normalize_color(int color)
{
	t_fvector3	c;

	c.x = ((color >> 16) & 0xFF) * TO_CHAR;
	c.y = ((color >> 8) & 0xFF) * TO_CHAR;
	c.z = (color & 0xFF) * TO_CHAR;
	return (c);
}

inline unsigned char	to_char(float n)
{
	if (n <= 0.0)
		return (0);
	if (n >= 1.0f)
		return (255);
	return (n * 255.0f);
}

int	normalized_to_rgb(t_fvector3 normalized)
{
	return ((to_char(normalized.x) << 16)
		| (to_char(normalized.y) << 8)
		| to_char(normalized.z));
}
