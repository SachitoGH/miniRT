/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:09:37 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/28 20:14:41 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

void	set_rt_null(t_minirt *rt)
{
	rt->mlx.mlx = NULL;
	rt->mlx.win.ptr = NULL;
	rt->control.ptr = NULL;
	rt->control.bg_color = CONTROL_BACKGROUND;
	rt->control.widgets = NULL;
	rt->general.ptr = NULL;
	rt->general.bg_color = CONTROL_BACKGROUND;
	rt->general.widgets = NULL;
	rt->elem = NULL;
	rt->spinners = NULL;
	rt->render.ptr = NULL;
	rt->render.bg_color = RENDER_BACKGROUND;
	rt->render.widgets = NULL;
	rt->scene.lights = NULL;
	rt->scene.objects = NULL;
	rt->scene.textures = NULL;
	rt->scene.amount_lights = 0;
	rt->scene.amount_objects = 0;
	rt->scene.amount_textures = 0;
	rt->scene.background.rgb = DEF_RENDER_COLOR;
	rt->scene.background.normalized = normalize_color(rt->scene.background.rgb);
}

void	set_floats(t_number_spinner *spinners)
{
	t_number32	min;
	t_number32	max;

	min.decimal = MIN_BRIGHTNESS;
	max.decimal = MAX_BRIGHTNESS;
	set_spinner_values(&spinners[3], min, max, true);
	min.decimal = MIN_VALUES;
	max.decimal = MAX_VALUES;
	set_spinner_values(&spinners[5], min, max, true);
	set_spinner_values(&spinners[6], min, max, true);
	set_spinner_values(&spinners[7], min, max, true);
	set_spinner_values(&spinners[8], min, max, true);
	set_spinner_values(&spinners[9], min, max, true);
	set_spinner_values(&spinners[10], min, max, true);
	set_spinner_values(&spinners[11], min, max, true);
	set_spinner_values(&spinners[12], min, max, true);
	set_spinner_values(&spinners[13], min, max, true);
	spinners[8].step.decimal = ROTATION;
	spinners[9].step.decimal = ROTATION;
	spinners[10].step.decimal = ROTATION;
}

void	set_integers(t_number_spinner *spinners)
{
	t_number32	min;
	t_number32	max;

	min.integer = MIN_COLOR;
	max.integer = MAX_COLOR;
	set_spinner_values(&spinners[0], min, max, false);
	set_spinner_values(&spinners[1], min, max, false);
	set_spinner_values(&spinners[2], min, max, false);
	set_spinner_values(&spinners[14], min, max, false);
	set_spinner_values(&spinners[15], min, max, false);
	set_spinner_values(&spinners[16], min, max, false);
	min.integer = MIN_FOV;
	max.integer = MAX_FOV;
	set_spinner_values(&spinners[4], min, max, false);
}

void	init_params(t_number_spinner *spinners, int amount)
{
	int	i;

	i = -1;
	while (++i < amount)
	{
		init_number_spinner(&spinners[i], PARAMS_PADDING * 2, 0, true);
		spinners[i].spinner.widget.draw_strngs = draw_number_spinner_strings;
		spinners[i].spinner.decrease.onclick = decrease_val;
		spinners[i].spinner.increase.onclick = increase_val;
	}
	set_integers(spinners);
	set_floats(spinners);
}

void	link_spinners(t_minirt *rt)
{
	int	i;
	int	j;

	i = -1;
	while (++i < CONTROL_PARAMS)
		rt->control.widgets[i] = &rt->spinners[i].spinner.widget;
	j = -1;
	while (++j < GENERAL_PARAMS)
		rt->general.widgets[j] = &rt->spinners[i++].spinner.widget;
}
