/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fvec3_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:56:31 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/21 17:46:18 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/dimensions.h"

inline t_fvector4	add_vec4(t_fvector4 v1, t_fvector4 v2)
{
	return ((t_fvector4){v1.w + v2.w, v1.x + v2.x, v1.y + v2.y, v1.z + v2.z});
}

inline t_fvector4	substract_vec4(t_fvector4 v1, t_fvector4 v2)
{
	return ((t_fvector4){v1.w - v2.w, v1.x - v2.x, v1.y - v2.y, v1.z - v2.z});
}

inline t_fvector4	multiply_vec4(t_fvector4 v1, t_fvector4 v2)
{
	return ((t_fvector4){v1.w * v2.w, v1.x * v2.x, v1.y * v2.y, v1.z * v2.z});
}

inline t_fvector4	divide_vec4(t_fvector4 v1, t_fvector4 v2)
{
	return ((t_fvector4){v1.w / v2.w, v1.x / v2.x, v1.y / v2.y, v1.z / v2.z});
}

inline float	dot_product4(t_fvector4 v1, t_fvector4 v2)
{
	return (v1.w * v2.w + v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}
