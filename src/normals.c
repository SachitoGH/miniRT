/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 21:23:06 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/28 19:05:25 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

t_fvector4	normal_ellipsoid(t_object3d *obj, t_fvector4 hit)
{
	(void)obj;
	hit.w = 0;
	return (hit);
}

t_fvector4	normal_cuboid(t_object3d *obj, t_fvector4 hit)
{
	t_fvector4	abs;
	float		max;

	(void)obj;
	abs = abs_vec4(hit);
	max = fmaxf(abs.x, fmaxf(abs.y, abs.z));
	if (equal(max, abs.x))
		return (vector(hit.x, 0, 0));
	else if (equal(max, abs.y))
		return (vector(0, hit.y, 0));
	return (vector(0, 0, hit.z));
}

t_fvector4	normal_conoid(t_object3d *obj, t_fvector4 hit)
{
	float	dist;

	dist = hit.x * hit.x + hit.z * hit.z;
	if (dist < obj->special.max * obj->special.max
		&& hit.y >= obj->special.max - F_EPSILON)
		return (vector(0, 1, 0));
	if (dist < obj->special.min * obj->special.min
		&& hit.y <= obj->special.min + F_EPSILON)
		return (vector(0, -1, 0));
	dist = sqrtf(dist);
	if (hit.y > F_EPSILON)
		dist = -dist;
	return (vector(hit.x, dist, hit.z));
}

t_fvector4	normal_plane(t_object3d *obj, t_fvector4 hit)
{
	(void)hit;
	(void)obj;
	return (vector(0, 1, 0));
}

t_fvector4	normal_cylinder(t_object3d *obj, t_fvector4 hit)
{
	float	dist;

	dist = hit.x * hit.x + hit.z * hit.z;
	if (dist < 1.0f && hit.y >= obj->special.max - F_EPSILON)
		return (vector(0, 1, 0));
	if (dist < 1.0f && hit.y <= obj->special.min + F_EPSILON)
		return (vector(0, -1, 0));
	return (vector(hit.x, 0, hit.z));
}
