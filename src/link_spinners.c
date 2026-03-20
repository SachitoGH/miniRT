/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_spinners.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:28:28 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/18 17:39:40 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

static void	object(t_minirt *rt)
{
	t_object3d	*obj;

	obj = (t_object3d *) rt->elem;
	rt->spinners[5].value.decimal = obj->position.x;
	rt->spinners[6].value.decimal = obj->position.y;
	rt->spinners[7].value.decimal = obj->position.z;
	rt->spinners[8].value.decimal = obj->e_rotation.x;
	rt->spinners[9].value.decimal = obj->e_rotation.y;
	rt->spinners[10].value.decimal = obj->e_rotation.z;
	rt->spinners[11].value.decimal = obj->scale.x;
	rt->spinners[12].value.decimal = obj->scale.y;
	rt->spinners[13].value.decimal = obj->scale.z;
	rt->spinners[14].value.integer = (obj->color.rgb >> 16) & 0xFF;
	rt->spinners[15].value.integer = (obj->color.rgb >> 8) & 0xFF;
	rt->spinners[16].value.integer = obj->color.rgb & 0xFF;
}

static void	light(t_minirt *rt)
{
	t_light	*obj;

	obj = (t_light *) rt->elem;
	rt->spinners[5].value.decimal = obj->position.x;
	rt->spinners[6].value.decimal = obj->position.y;
	rt->spinners[7].value.decimal = obj->position.z;
	rt->spinners[14].value.integer = (obj->color.rgb >> 16) & 0xFF;
	rt->spinners[15].value.integer = (obj->color.rgb >> 8) & 0xFF;
	rt->spinners[16].value.integer = obj->color.rgb & 0xFF;
	rt->spinners[17].value.decimal = obj->brightness;
}

void	link_object(t_minirt *rt)
{
	if (rt->elem_select == OBJECT)
		object(rt);
	else if (rt->elem_select == LIGHT)
		light(rt);
}

void	link_control_values(t_minirt *rt)
{
	rt->spinners[0].value.integer
		= (rt->scene.camera.alight_color.rgb >> 16) & 0xFF;
	rt->spinners[1].value.integer
		= (rt->scene.camera.alight_color.rgb >> 8) & 0xFF;
	rt->spinners[2].value.integer = rt->scene.camera.alight_color.rgb & 0xFF;
	rt->spinners[3].value.decimal = rt->scene.camera.alight_brightness;
	rt->spinners[4].value.integer = rt->scene.camera.viewport.fov;
}
