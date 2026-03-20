/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fvec4_operations3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 00:26:23 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/30 03:22:46 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/dimensions.h"

inline t_fvector4	normalize4(t_fvector4 v)
{
	float	magnitude;

	magnitude = get_length4(v);
	if (magnitude != 0.0)
		return (dividef4(v, magnitude));
	return (v);
}

inline t_fvector4	min_vec4(t_fvector4 a, t_fvector4 b)
{
	return ((t_fvector4){
		.w = fminf(a.w, b.w),
		.x = fminf(a.x, b.x),
		.y = fminf(a.y, b.y),
		.z = fminf(a.z, b.z)
	});
}

inline t_fvector4	max_vec4(t_fvector4 a, t_fvector4 b)
{
	return ((t_fvector4){
		.w = fmaxf(a.w, b.w),
		.x = fmaxf(a.x, b.x),
		.y = fmaxf(a.y, b.y),
		.z = fmaxf(a.z, b.z)
	});
}

inline t_fvector4	point(float x, float y, float z)
{
	return ((t_fvector4){1.0f, x, y, z});
}

inline t_fvector4	vector(float x, float y, float z)
{
	return ((t_fvector4){0.0f, x, y, z});
}
