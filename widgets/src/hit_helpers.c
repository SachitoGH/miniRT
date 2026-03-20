/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:16:16 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/28 19:01:17 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

bool	check_cap(t_fvector4 origin, t_fvector4 dir, float t, float limit)
{
	float	x;
	float	z;

	x = origin.x + t * dir.x;
	z = origin.z + t * dir.z;
	return ((x * x + z * z) <= limit * limit);
}

void	manage_hits_special(t_object3d *obj, t_fvector4 dir, t_fvector4 origin,
	t_render_info *i)
{
	float	a;
	float	b;

	a = fminf(i->t[0], i->t[1]);
	b = fmaxf(i->t[0], i->t[1]);
	i->t[0] = a;
	i->t[1] = b;
	a = origin.y + i->t[0] * dir.y;
	b = origin.y + i->t[1] * dir.y;
	i->n_hits = d_in_bounds(a, obj->special.min, obj->special.max);
	if (!i->n_hits)
		i->t[0] = i->t[1];
	i->n_hits += d_in_bounds(b, obj->special.min, obj->special.max);
}

bool	quadratic_formula(float a, float b, float c, t_render_info *i)
{
	float	discriminant;

	discriminant = b * b - a * c;
	if (discriminant > F_EPSILON)
	{
		discriminant = sqrtf(discriminant);
		i->t[0] = (-b - discriminant) / a;
		i->t[1] = (-b + discriminant) / a;
		return (true);
	}
	return (false);
}

void	cap_conoid(t_object3d *obj, t_fvector4 dir, t_fvector4 origin,
	t_render_info *i)
{
	i->t[i->n_hits] = (obj->special.min - origin.y) / dir.y;
	i->n_hits += check_cap(origin, dir, i->t[i->n_hits],
			obj->special.min);
	i->t[i->n_hits] = (obj->special.max - origin.y) / dir.y;
	i->n_hits += check_cap(origin, dir, i->t[i->n_hits],
			obj->special.max);
}
