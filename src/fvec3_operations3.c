/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fvec3_operations3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 00:26:23 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/21 18:01:09 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/dimensions.h"

inline t_fvector3	abs_vec(t_fvector3 v)
{
	return ((t_fvector3){fabsf(v.x), fabsf(v.y), fabsf(v.z)});
}

inline float	get_length(t_fvector3 v)
{
	return (sqrtf(v.x * v.x + v.y * v.y + v.z * v.z));
}

inline t_fvector3	normalize(t_fvector3 v)
{
	float	magnitude;

	magnitude = get_length(v);
	if (magnitude != 0.0)
		return (dividef(v, magnitude));
	return (v);
}

inline t_fvector3	min_vec(t_fvector3 a, t_fvector3 b)
{
	return ((t_fvector3){
		.x = fminf(a.x, b.x),
		.y = fminf(a.y, b.y),
		.z = fminf(a.z, b.z)
	});
}

inline t_fvector3	max_vec(t_fvector3 a, t_fvector3 b)
{
	return ((t_fvector3){
		.x = fmaxf(a.x, b.x),
		.y = fmaxf(a.y, b.y),
		.z = fmaxf(a.z, b.z)
	});
}
