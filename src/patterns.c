/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:20:03 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/23 14:57:54 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

t_fvector3	gradient_at(t_pattern *p, t_fvector4 point)
{
	t_fvector3	distance;
	float		fraction;

	distance = substract_vec(p->color_b.normalized, p->color_a.normalized);
	fraction = point.x - floorf(point.x);
	return (add_vec(p->color_a.normalized, multiplyf(distance, fraction)));
}

t_fvector3	strip_at(t_pattern *p, t_fvector4 point)
{
	if ((int)floorf(point.x) % 2 == 0)
		return (p->color_a.normalized);
	return (p->color_b.normalized);
}

t_fvector3	ring_at(t_pattern *p, t_fvector4 point)
{
	float	dist;

	dist = sqrtf(point.x * point.x + point.z * point.z);
	if (((int)floorf(dist + F_EPSILON)) % 2 == 0)
		return (p->color_a.normalized);
	return (p->color_b.normalized);
}

t_fvector3	check_at(t_pattern *p, t_fvector4 point)
{
	int	sum;

	sum = (int)floorf(point.x + F_EPSILON)
		+ (int)floorf(point.y + F_EPSILON)
		+ (int)floorf(point.z + F_EPSILON);
	if ((sum % 2) == 0)
		return (p->color_a.normalized);
	return (p->color_b.normalized);
}
