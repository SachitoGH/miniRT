/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:38:02 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/28 20:09:57 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/dimensions.h"

t_fvector4	smatrix4_multiply_vec4(t_smatrix4 *m, t_fvector4 t)
{
	float	w;
	float	x;
	float	y;
	float	z;

	x = m->data[0][0] * t.x + m->data[0][1] * t.y + m->data[0][2] * t.z
		+ m->data[0][3] * t.w;
	y = m->data[1][0] * t.x + m->data[1][1] * t.y + m->data[1][2] * t.z
		+ m->data[1][3] * t.w;
	z = m->data[2][0] * t.x + m->data[2][1] * t.y + m->data[2][2] * t.z
		+ m->data[2][3] * t.w;
	w = m->data[3][0] * t.x + m->data[3][1] * t.y + m->data[3][2] * t.z
		+ m->data[3][3] * t.w;
	return ((t_fvector4){w, x, y, z});
}

t_smatrix4	smatrix4_multiply(t_smatrix4 *a, t_smatrix4 *b)
{
	t_smatrix4	result;
	int			i;
	int			j;
	int			k;

	i = -1;
	result = smatrix4_zero();
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			k = -1;
			while (++k < 4)
				result.data[i][j] += a->data[i][k] * b->data[k][j];
		}
	}
	return (result);
}

t_smatrix4	smatrix4_transpose(t_smatrix4 *m)
{
	t_smatrix4	result;
	int			i;
	int			j;

	i = -1;
	result = smatrix4_zero();
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			result.data[i][j] = m->data[j][i];
	}
	return (result);
}

t_smatrix4	smatrix4_submatrix(t_smatrix4 *m, int row, int col, int size)
{
	t_smatrix4	result;
	int			res_row;
	int			res_col;
	int			i;
	int			j;

	res_row = 0;
	i = -1;
	result = smatrix4_zero();
	while (++i < size)
	{
		if (i == row)
			continue ;
		res_col = 0;
		j = -1;
		while (++j < size)
		{
			if (j == col)
				continue ;
			result.data[res_row][res_col] = m->data[i][j];
			res_col++;
		}
		res_row++;
	}
	return (result);
}

t_smatrix4	smatrix4_rotate(t_fvector3 rad)
{
	t_smatrix4	res;
	t_smatrix4	temp;

	res = smatrix4_rotate_z(rad.z);
	temp = smatrix4_rotate_y(rad.y);
	res = smatrix4_multiply(&res, &temp);
	temp = smatrix4_rotate_x(rad.x);
	res = smatrix4_multiply(&res, &temp);
	return (res);
}
