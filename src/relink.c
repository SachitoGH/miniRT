/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relink.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:40:31 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/23 23:15:13 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

static void	object(t_minirt *rt)
{
	t_object3d	*obj;

	obj = (t_object3d *) rt->elem;
	obj->position.x = rt->spinners[5].value.decimal;
	obj->position.y = rt->spinners[6].value.decimal;
	obj->position.z = rt->spinners[7].value.decimal;
	obj->e_rotation.x = rt->spinners[8].value.decimal;
	obj->e_rotation.y = rt->spinners[9].value.decimal;
	obj->e_rotation.z = rt->spinners[10].value.decimal;
	obj->scale.x = rt->spinners[11].value.decimal;
	obj->scale.y = rt->spinners[12].value.decimal;
	obj->scale.z = rt->spinners[13].value.decimal;
	obj->color.rgb = (rt->spinners[14].value.integer << 16)
		| (rt->spinners[15].value.integer << 8)
		| rt->spinners[16].value.integer;
	obj->color.normalized = normalize_color(obj->color.rgb);
	calculate_object(obj, &rt->scene.camera);
}

static void	light(t_minirt *rt)
{
	t_light	*obj;

	obj = (t_light *) rt->elem;
	obj->position.x = rt->spinners[5].value.decimal;
	obj->position.y = rt->spinners[6].value.decimal;
	obj->position.z = rt->spinners[7].value.decimal;
	obj->color.rgb = (rt->spinners[14].value.integer << 16)
		| (rt->spinners[15].value.integer << 8)
		| rt->spinners[16].value.integer;
	obj->color.normalized = normalize_color(obj->color.rgb);
	obj->brightness = rt->spinners[17].value.decimal;
}

void	relink_object(t_minirt *rt)
{
	if (rt->elem_select == OBJECT)
		object(rt);
	else if (rt->elem_select == LIGHT)
		light(rt);
}

void	relink_control_values(t_minirt *rt)
{
	rt->scene.camera.alight_color.rgb = (rt->spinners[0].value.integer << 16)
		| (rt->spinners[1].value.integer << 8) | rt->spinners[2].value.integer;
	rt->scene.camera.alight_color.normalized
		= normalize_color(rt->scene.camera.alight_color.rgb);
	rt->scene.camera.alight_brightness = rt->spinners[3].value.decimal;
	rt->scene.camera.viewport.fov = rt->spinners[4].value.integer;
}
