/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawable_container.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 01:06:18 by dzapata           #+#    #+#             */
/*   Updated: 2025/04/03 15:59:29 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/widgets.h"

void	drwcontainer_draw_rectangle(t_image *img, void *self)
{
	t_drawable_container	*dc;
	t_ivector2				points[2];

	dc = (t_drawable_container *) self;
	points[0].x = dc->widget.x;
	points[0].y = dc->widget.y;
	points[1].x = dc->widget.x + get_widget_width(&dc->widget)
		+ dc->margin_left + dc->margin_right;
	points[1].y = dc->widget.y + get_widget_height(&dc->widget)
		+ dc->margin_top + dc->margin_bottom;
	draw_square(img, points, dc->bg_color, true);
	draw_square(img, points, dc->border_color, false);
}

void	drwcontainer_init(t_drawable_container *dc, t_ivector2 position,
	t_ivector2 size)
{
	dc->widget.draw = drwcontainer_draw_rectangle;
	dc->widget.draw_strngs = NULL;
	dc->widget.object = dc;
	dc->widget.x = position.x;
	dc->widget.y = position.y;
	dc->widget.width = size.x;
	dc->widget.height = size.y;
	dc->widget.is_visible = true;
	dc->margin_top = DEF_MARGIN_TOP;
	dc->margin_left = DEF_MARGIN_LEFT;
	dc->margin_right = DEF_MARGIN_RIGHT;
	dc->margin_bottom = DEF_MARGIN_BOTTOM;
	dc->bg_color = DEF_BGCOLOR;
	dc->border_color = DEF_BORDERCOLOR;
	default_min_size(&dc->widget);
	default_max_size(&dc->widget);
}
