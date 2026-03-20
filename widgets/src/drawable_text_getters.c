/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawable_text_getters.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 01:51:00 by dzapata           #+#    #+#             */
/*   Updated: 2025/03/31 16:43:59 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/widgets.h"

int	get_draw_text_x(t_drawable_text *t, t_drawable_container *c)
{
	int	alignment;

	alignment = t->alignment & HAL_MASK;
	if (alignment == HAL_LEFT)
		return (c->widget.x + c->margin_left);
	else if (alignment == HAL_CENTER)
		return (c->widget.x + c->margin_left + (get_widget_width(&c->widget)
				- calculate_label_width(t->text)) / 2);
	else if (alignment == HAL_RIGHT)
		return (c->widget.x + c->margin_left + (get_widget_width(&c->widget)
				- calculate_label_width(t->text)));
	return (c->widget.x + c->margin_left);
}

int	get_draw_text_y(t_drawable_text *t, t_drawable_container *c)
{
	int	alignment;

	alignment = t->alignment & VAL_MASK;
	if (alignment == VAL_TOP)
		return (c->widget.y + c->margin_top);
	else if (alignment == VAL_CENTER)
		return (c->widget.y + c->margin_top
			+ (get_widget_height(&c->widget) - HEIGHT_PER_CHAR) / 2);
	else if (alignment == VAL_BOTTOM)
		return (c->widget.y + c->margin_top
			+ (get_widget_height(&c->widget) - HEIGHT_PER_CHAR));
	return (c->widget.y + c->margin_top);
}
