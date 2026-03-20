/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fvec3_operations2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:04:17 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/22 16:45:31 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/dimensions.h"

inline t_fvector3	multiplyf(t_fvector3 v, float f)
{
	return ((t_fvector3){v.x * f, v.y * f, v.z * f});
}

inline t_fvector3	dividef(t_fvector3 v, float f)
{
	return (multiplyf(v, (1 / f)));
}

inline t_fvector3	addf(t_fvector3 v, float f)
{
	return ((t_fvector3){v.x + f, v.y + f, v.z + f});
}

inline t_fvector3	negate(t_fvector3 v)
{
	return ((t_fvector3){-v.x, -v.y, -v.z});
}

inline t_fvector3	cross_product(t_fvector3 v1, t_fvector3 v2)
{
	return ((t_fvector3){
		v1.y * v2.z - v1.z * v2.y,
		v1.z * v2.x - v1.x * v2.z,
		v1.x * v2.y - v1.y * v2.x
	});
}
