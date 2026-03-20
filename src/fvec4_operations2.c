/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fvec4_operations2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:04:17 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/30 03:23:15 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/dimensions.h"

inline t_fvector4	multiplyf4(t_fvector4 v, float f)
{
	return ((t_fvector4){v.w * f, v.x * f, v.y * f, v.z * f});
}

inline t_fvector4	dividef4(t_fvector4 v, float f)
{
	return ((t_fvector4){v.w / f, v.x / f, v.y / f, v.z / f});
}

inline t_fvector4	negate4(t_fvector4 v)
{
	return ((t_fvector4){-v.w, -v.x, -v.y, -v.z});
}

inline t_fvector4	cross_product4(t_fvector4 v1, t_fvector4 v2)
{
	return ((t_fvector4){
		0.0f,
		v1.y * v2.z - v1.z * v2.y,
		v1.z * v2.x - v1.x * v2.z,
		v1.x * v2.y - v1.y * v2.x
	});
}

inline float	get_length4(t_fvector4 v)
{
	return (sqrtf(v.w * v.w + v.x * v.x + v.y * v.y + v.z * v.z));
}
