/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawable_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 01:27:12 by dzapata           #+#    #+#             */
/*   Updated: 2025/03/31 20:31:43 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/widgets.h"

void	drwcontainer_draw_string(t_mlx *mlx, t_image *img, t_drawable_text *t,
		t_drawable_container *dc)
{
	t_ivector2	position;

	if (t && t->text && dc)
	{
		position.x = get_draw_text_x(t, dc) + 1;
		position.y = get_draw_text_y(t, dc);
		if (img)
		{
			position.x += img->x;
			position.y += img->y;
		}
		mlx_string_put(mlx->mlx, mlx->win.ptr, position.x + TEXT_OFFSETX,
			position.y + TEXT_OFFSETY, t->color, t->text);
	}
}

void	drwtext_init(t_drawable_text *t, char *text, int color, int alignment)
{
	t->text = text;
	t->color = color;
	t->alignment = alignment;
}
