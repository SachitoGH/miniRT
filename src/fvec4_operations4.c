/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fvec4_operations4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:19:53 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/28 01:38:36 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/dimensions.h"

inline t_fvector4	addf4(t_fvector4 v, float f)
{
	return ((t_fvector4){v.w + f, v.x + f, v.y + f, v.z + f});
}

inline t_fvector4	substractf4(t_fvector4 v, float f)
{
	return ((t_fvector4){v.w - f, v.x - f, v.y - f, v.z - f});
}

inline t_fvector4	abs_vec4(t_fvector4 v)
{
	return ((t_fvector4){fabsf(v.w), fabsf(v.x), fabsf(v.y), fabsf(v.z)});
}

inline	t_fvector4	to_point4(t_fvector3 v)
{
	return ((t_fvector4){1.0f, v.x, v.y, v.z});
}

inline	t_fvector4	to_vector4(t_fvector3 v)
{
	return ((t_fvector4){0.0f, v.x, v.y, v.z});
}
