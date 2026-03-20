/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fvec3_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:56:31 by dzapata           #+#    #+#             */
/*   Updated: 2025/04/29 00:29:37 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/dimensions.h"

inline t_fvector3	add_vec(t_fvector3 v1, t_fvector3 v2)
{
	return ((t_fvector3){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z});
}

inline t_fvector3	substract_vec(t_fvector3 v1, t_fvector3 v2)
{
	return ((t_fvector3){v1.x - v2.x, v1.y - v2.y, v1.z - v2.z});
}

inline t_fvector3	multiply_vec(t_fvector3 v1, t_fvector3 v2)
{
	return ((t_fvector3){v1.x * v2.x, v1.y * v2.y, v1.z * v2.z});
}

inline t_fvector3	divide_vec(t_fvector3 v1, t_fvector3 v2)
{
	return ((t_fvector3){v1.x / v2.x, v1.y / v2.y, v1.z / v2.z});
}

inline float	dot_product(t_fvector3 v1, t_fvector3 v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}
