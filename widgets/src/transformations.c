/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:11:41 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/27 16:23:33 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/dimensions.h"

t_smatrix4	smatrix4_translate(t_fvector3 p)
{
	t_smatrix4	res;

	res = smatrix4_identity();
	res.data[0][3] = p.x;
	res.data[1][3] = p.y;
	res.data[2][3] = p.z;
	return (res);
}

t_smatrix4	smatrix4_scale(t_fvector3 p)
{
	t_smatrix4	res;

	res = smatrix4_identity();
	res.data[0][0] = p.x;
	res.data[1][1] = p.y;
	res.data[2][2] = p.z;
	return (res);
}

t_smatrix4	smatrix4_rotate_x(float rad)
{
	t_smatrix4	res;
	float		sin;
	float		cos;

	res = smatrix4_identity();
	sin = sinf(rad);
	cos = cosf(rad);
	res.data[1][1] = cos;
	res.data[1][2] = -sin;
	res.data[2][1] = sin;
	res.data[2][2] = cos;
	return (res);
}

t_smatrix4	smatrix4_rotate_y(float rad)
{
	t_smatrix4	res;
	float		sin;
	float		cos;

	res = smatrix4_identity();
	sin = sinf(rad);
	cos = cosf(rad);
	res.data[0][0] = cos;
	res.data[0][2] = sin;
	res.data[2][0] = -sin;
	res.data[2][2] = cos;
	return (res);
}

t_smatrix4	smatrix4_rotate_z(float rad)
{
	t_smatrix4	res;
	float		sin;
	float		cos;

	res = smatrix4_identity();
	sin = sinf(rad);
	cos = cosf(rad);
	res.data[0][0] = cos;
	res.data[0][1] = -sin;
	res.data[1][0] = sin;
	res.data[1][1] = cos;
	return (res);
}
