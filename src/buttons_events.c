/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 04:06:21 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/30 05:09:38 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

void	redraw(t_event *event)
{
	mlx_put_image_to_window(event->rt->mlx.mlx, event->rt->mlx.win.ptr,
		event->img->ptr, event->img->x, event->img->y);
	draw_image_widgets_strings(&event->rt->mlx, event->img);
	if (event->img == &event->rt->control)
	{
		relink_control_values(event->rt);
		calculate_camera(&event->rt->scene.camera, &event->rt->render);
		calculate_objects_camera(&event->rt->scene);
		draw_control_strings(event->rt, event->img);
	}
	else if (event->img == &event->rt->general)
	{
		relink_object(event->rt);
		draw_general_strings(event->rt, &event->rt->general);
	}
	low_render(&event->rt->scene, &event->rt->render);
	mlx_put_image_to_window(event->rt->mlx.mlx, event->rt->mlx.win.ptr,
		event->rt->render.ptr, event->rt->render.x, event->rt->render.y);
}

bool	increase_spinner_val(t_number_spinner *param)
{
	if (param->is_decimal)
	{
		if (!d_in_bounds(param->value.decimal, param->low_limit.decimal,
				param->high_limit.decimal)
			|| !d_in_bounds(param->value.decimal + param->step.decimal,
				param->low_limit.decimal, param->high_limit.decimal))
			return (true);
		param->value.decimal += param->step.decimal;
	}
	else
	{
		if (!i_in_bounds(param->value.integer, param->low_limit.integer,
				param->high_limit.integer)
			|| !i_in_bounds(param->value.integer + param->step.integer,
				param->low_limit.integer, param->high_limit.integer))
			return (true);
		param->value.integer += param->step.integer;
	}
	return (false);
}

bool	decrease_spinner_val(t_number_spinner *param)
{
	if (param->is_decimal)
	{
		if (!d_in_bounds(param->value.decimal, param->low_limit.decimal,
				param->high_limit.decimal)
			|| !d_in_bounds(param->value.decimal - param->step.decimal,
				param->low_limit.decimal, param->high_limit.decimal))
			return (true);
		param->value.decimal -= param->step.decimal;
	}
	else
	{
		if (!i_in_bounds(param->value.integer, param->low_limit.integer,
				param->high_limit.integer)
			|| !i_in_bounds(param->value.integer - param->step.integer,
				param->low_limit.integer, param->high_limit.integer))
			return (true);
		param->value.integer -= param->step.integer;
	}
	return (0);
}

void	*increase_val(void *arg)
{
	t_event	*event;

	event = (t_event *) arg;
	if (increase_spinner_val(event->param))
		ft_printf("Maximun Value Reached.\n");
	else
		redraw(event);
	return (NULL);
}

void	*decrease_val(void *arg)
{
	t_event	*event;

	event = (t_event *) arg;
	if (decrease_spinner_val(event->param))
		ft_printf("Minimun Value Reached.\n");
	else
		redraw(event);
	return (NULL);
}
