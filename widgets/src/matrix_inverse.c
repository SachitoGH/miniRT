/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_inverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:10:58 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/27 16:22:04 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/dimensions.h"

t_smatrix4	smatrix4_inverse(t_smatrix4 *m)
{
	t_smatrix4	result;
	float		det;
	int			row;
	int			col;

	if (!is_invertible(m, 4))
		return (smatrix4_zero());
	det = smatrix4_determinant(m, 4);
	row = -1;
	while (++row < 4)
	{
		col = -1;
		while (++col < 4)
			result.data[col][row] = smatrix4_cofactor(m, row, col, 4) / det;
	}
	return (result);
}

float	smatrix4_minor(t_smatrix4 *m, int row, int col, int size)
{
	t_smatrix4	sub;

	sub = smatrix4_submatrix(m, row, col, size);
	return (smatrix4_determinant(&sub, size - 1));
}

float	smatrix4_determinant(t_smatrix4 *m, int size)
{
	float	det;
	int		col;

	if (size == 2)
		return ((m->data[0][0] * m->data[1][1])
			- (m->data[0][1] * m->data[1][0]));
	det = 0.0f;
	col = -1;
	while (++col < size)
		det += m->data[0][col] * smatrix4_cofactor(m, 0, col, size);
	return (det);
}

float	smatrix4_cofactor(t_smatrix4 *m, int row, int col, int size)
{
	float	minor_val;

	minor_val = smatrix4_minor(m, row, col, size);
	if ((row + col) % 2 == 0)
		return (minor_val);
	return (-minor_val);
}

int	is_invertible(t_smatrix4 *m, int size)
{
	return (fabs(smatrix4_determinant(m, size)) > F_EPSILON);
}
