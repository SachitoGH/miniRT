/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:30:57 by dzapata           #+#    #+#             */
/*   Updated: 2025/03/31 20:13:26 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/widgets.h"

// Verifies if a given widget is part of the image through its memory address
bool	image_has_widget(t_image *img, t_widget *w)
{
	unsigned int	i;

	if (img && w && img->widgets)
	{
		i = 0;
		while (i < img->amount_wigets)
		{
			if (img->widgets[i] == w)
				return (true);
			i++;
		}
	}
	return (false);
}

// Verifies if a given point is within the bounds of an image
bool	is_within_image(t_image *img, int x, int y)
{
	return (x >= img->x && ((long) x) <= img->x + img->width
		&& y >= img->y && ((long) y) <= img->y + img->height);
}
