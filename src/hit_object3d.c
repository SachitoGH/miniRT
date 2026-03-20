/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_object3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 01:35:05 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/30 02:59:09 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

bool	hit_ellipsoid(t_object3d *obj, t_fvector4 dir, t_fvector4 origin,
	t_render_info *i)
{
	float		a;
	float		b;
	float		discriminant;

	(void)obj;
	origin.w = 0.0f;
	a = dot_product4(dir, dir);
	b = dot_product4(dir, origin);
	discriminant = b * b - a * (dot_product4(origin, origin) - 1);
	if (discriminant <= F_EPSILON)
		return (false);
	discriminant = sqrtf(discriminant);
	i->t[0] = (-b - discriminant) / a;
	i->n_hits = i->t[0] > F_EPSILON;
	i->t[i->n_hits] = (-b + discriminant) / a;
	i->n_hits += i->t[i->n_hits] > F_EPSILON;
	return (i->n_hits);
}

bool	hit_cuboid(t_object3d *obj, t_fvector4 dir, t_fvector4 origin,
	t_render_info *i)
{
	t_fvector4	tmin;
	t_fvector4	tmax;
	t_fvector4	t1;
	t_fvector4	t2;

	(void)obj;
	t1 = divide_vec4(substractf4(negate4(origin), 1.0f), dir);
	t2 = divide_vec4(addf4(negate4(origin), 1.0f), dir);
	tmin = min_vec4(t1, t2);
	tmax = max_vec4(t1, t2);
	i->t[0] = fmaxf(fmaxf(tmin.x, tmin.y), tmin.z);
	i->n_hits = i->t[0] != INFINITY;
	i->t[i->n_hits] = fminf(fminf(tmax.x, tmax.y), tmax.z);
	i->n_hits += i->t[i->n_hits] != INFINITY;
	return (i->n_hits && i->t[0] <= i->t[1]);
}

bool	hit_conoid(t_object3d *obj, t_fvector4 dir, t_fvector4 origin,
	t_render_info *i)
{
	float	a;
	float	b;
	float	c;

	(void)obj;
	i->n_hits = 0;
	a = dir.x * dir.x - dir.y * dir.y + dir.z * dir.z;
	b = origin.x * dir.x - origin.y * dir.y + origin.z * dir.z;
	c = origin.x * origin.x - origin.y * origin.y + origin.z * origin.z;
	if (fabsf(a) > F_EPSILON)
	{
		if (quadratic_formula(a, b, c, i))
			manage_hits_special(obj, dir, origin, i);
	}
	else if (fabsf(b) > F_EPSILON)
	{
		i->t[0] = -c / (4 * b);
		i->n_hits = d_in_bounds(origin.y + i->t[0] * dir.y,
				obj->special.min, obj->special.max);
	}
	if (obj->special.closed && fabsf(dir.y) > F_EPSILON
		&& obj->special.min < obj->special.max)
		cap_conoid(obj, dir, origin, i);
	return (i->n_hits);
}

bool	hit_plane(t_object3d *obj, t_fvector4 dir, t_fvector4 origin,
	t_render_info *i)
{
	(void)obj;
	if (fabsf(dir.y) < F_EPSILON)
		return (false);
	i->t[0] = -origin.y / dir.y;
	i->n_hits = 1;
	return (true);
}

bool	hit_cylinder(t_object3d *obj, t_fvector4 dir, t_fvector4 origin,
	t_render_info *i)
{
	float	a;

	(void)obj;
	i->n_hits = 0;
	a = dir.x * dir.x + dir.z * dir.z;
	if (fabsf(a) > F_EPSILON && quadratic_formula(a,
			origin.x * dir.x + origin.z * dir.z,
			origin.x * origin.x + origin.z * origin.z - 1, i))
		manage_hits_special(obj, dir, origin, i);
	if (obj->special.closed && fabsf(dir.y) > F_EPSILON
		&& obj->special.min < obj->special.max)
	{
		i->t[i->n_hits] = (obj->special.min - origin.y) / dir.y;
		i->n_hits += check_cap(origin, dir, i->t[i->n_hits], 1.0f);
		i->t[i->n_hits] = (obj->special.max - origin.y) / dir.y;
		i->n_hits += check_cap(origin, dir, i->t[i->n_hits], 1.0f);
	}
	return (i->n_hits);
}
