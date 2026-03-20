/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 22:20:56 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/28 03:30:14 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

int	key_press(int key, t_minirt *rt)
{
	rt->key = key;
	if (key == ESC_KEY)
		end(rt);
	else if (key == W_KEY)
		move_forward(rt, STEPS);
	else if (key == S_KEY)
		move_forward(rt, -STEPS);
	else if (key == A_KEY)
		move_right(rt, STEPS);
	else if (key == D_KEY)
		move_right(rt, -STEPS);
	else if (key == SPACE_BAR)
		move_up(rt, STEPS);
	else if (key == C_KEY)
		move_up(rt, -STEPS);
	else if (key == ARROW_LEFT)
		rotate_sides(rt, ROTATION);
	else if (key == ARROW_RIGHT)
		rotate_sides(rt, -ROTATION);
	else if (key == ARROW_UP)
		rotate_up(rt, ROTATION);
	else if (key == ARROW_DOWN)
		rotate_up(rt, -ROTATION);
	else if (key == F_KEY)
	{
		render(&rt->scene, &rt->render);
		mlx_put_image_to_window(rt->mlx.mlx, rt->mlx.win.ptr,
		rt->render.ptr, rt->render.x, rt->render.y);
	}
	return (0);
}

int	key_release(int key, t_minirt *rt)
{
	(void) key;
	rt->key = -1;
	return (0);
}

int	mouse_press(int button, int x, int y, t_minirt *rt)
{
	if (button == MOUSE_LEFT)
	{
		rt->mouse.draggin = 1;
		rt->mouse.last_x = x;
		rt->mouse.last_y = y;
		if (is_within_image(&rt->render, x, y))
			select_object(rt, x, y);
		else
			has_clicked_button(rt, x, y);
	}
	return (0);
}

int	mouse_release(int button, int x, int y, t_minirt *rt)
{
	(void) x;
	(void) y;
	if (button == MOUSE_LEFT)
		rt->mouse.draggin = 0;
	return (0);
}

int	mouse_motion(int x, int y, t_minirt *rt)
{
	if (x >= rt->render.x && y >= rt->render.y)
		return (0);
	return (0);
}
