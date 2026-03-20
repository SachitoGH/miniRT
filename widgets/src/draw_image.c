/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 02:44:32 by dzapata           #+#    #+#             */
/*   Updated: 2025/03/25 18:51:20 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/widgets.h"

void	draw_image_widgets_strings(t_mlx *mlx, t_image *img)
{
	unsigned int	i;

	if (img->widgets)
	{
		i = 0;
		while (i < img->amount_wigets)
		{
			if (img->widgets[i]->draw_strngs && img->widgets[i]->is_visible)
				img->widgets[i]->draw_strngs(mlx, img, img->widgets[i]->object);
			i++;
		}
	}
}

void	draw_image_widgets(t_image *img)
{
	unsigned int	i;

	if (img->widgets)
	{
		i = 0;
		while (i < img->amount_wigets)
		{
			if (img->widgets[i]->draw && img->widgets[i]->is_visible)
				img->widgets[i]->draw(img, img->widgets[i]->object);
			i++;
		}
	}
}

void	draw_image_window(t_mlx *mlx, t_image *img)
{
	draw_image_widgets(img);
	mlx_put_image_to_window(mlx->mlx, mlx->win.ptr, img->ptr, img->x, img->y);
	draw_image_widgets_strings(mlx, img);
}
