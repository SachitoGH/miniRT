/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimensions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:39:36 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/28 20:11:30 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIMENSIONS_H
# define DIMENSIONS_H
# include "math.h"

# define F_EPSILON	1.0e-4f

typedef struct s_fvector3
{
	float	x;
	float	y;
	float	z;
}	t_fvector3;

typedef struct s_fvector4
{
	float	w;
	float	x;
	float	y;
	float	z;
}	t_fvector4;

typedef struct t_smatrix4
{
	float	data[4][4];
}	t_smatrix4;

//f_vector3 operations

t_fvector3		add_vec(t_fvector3 v1, t_fvector3 v2);
t_fvector3		substract_vec(t_fvector3 v1, t_fvector3 v2);
t_fvector3		multiply_vec(t_fvector3 v1, t_fvector3 v2);
t_fvector3		divide_vec(t_fvector3 v1, t_fvector3 v2);
float			dot_product(t_fvector3 v1, t_fvector3 v2);
float			get_length(t_fvector3 v);
t_fvector3		cross_product(t_fvector3 v1, t_fvector3 v2);
t_fvector3		addf(t_fvector3 v, float f);
t_fvector3		negate(t_fvector3 v);
t_fvector3		multiplyf(t_fvector3 v, float f);
t_fvector3		dividef(t_fvector3 v, float f);
t_fvector3		min_vec(t_fvector3 a, t_fvector3 b);
t_fvector3		max_vec(t_fvector3 a, t_fvector3 b);
t_fvector3		normalize(t_fvector3 v);
t_fvector3		abs_vec(t_fvector3 v);

//f_vector4 operations

t_fvector4		add_vec4(t_fvector4 v1, t_fvector4 v2);
t_fvector4		substract_vec4(t_fvector4 v1, t_fvector4 v2);
t_fvector4		multiply_vec4(t_fvector4 v1, t_fvector4 v2);
t_fvector4		divide_vec4(t_fvector4 v1, t_fvector4 v2);
float			dot_product4(t_fvector4 v1, t_fvector4 v2);
float			get_length4(t_fvector4 v);
t_fvector4		cross_product4(t_fvector4 v1, t_fvector4 v2);
t_fvector4		multiplyf4(t_fvector4 v, float f);
t_fvector4		dividef4(t_fvector4 v, float f);
t_fvector4		min_vec4(t_fvector4 a, t_fvector4 b);
t_fvector4		max_vec4(t_fvector4 a, t_fvector4 b);
t_fvector4		normalize4(t_fvector4 v);
t_fvector4		negate4(t_fvector4 v);
t_fvector4		addf4(t_fvector4 v, float f);
t_fvector4		substractf4(t_fvector4 v, float f);
t_fvector4		abs_vec4(t_fvector4 v);
t_fvector4		point(float x, float y, float z);
t_fvector4		to_point4(t_fvector3 v);
t_fvector4		vector(float x, float y, float z);
t_fvector4		to_vector4(t_fvector3 v);

//Square matrix4

t_smatrix4		smatrix4_identity(void);
t_smatrix4		smatrix4_zero(void);
t_smatrix4		smatrix4_multiply(t_smatrix4 *a, t_smatrix4 *b);
t_smatrix4		smatrix4_transpose(t_smatrix4 *m);
t_smatrix4		smatrix4_submatrix(t_smatrix4 *m, int row, int col, int size);
t_smatrix4		smatrix4_inverse(t_smatrix4 *m);
t_fvector4		smatrix4_multiply_vec4(t_smatrix4 *m, t_fvector4 t);
float			smatrix4_cofactor(t_smatrix4 *m, int row, int col, int size);
float			smatrix4_minor(t_smatrix4 *m, int row, int col, int size);
float			smatrix4_determinant(t_smatrix4 *m, int size);
int				is_invertible(t_smatrix4 *m, int size);

//Trasformations

t_smatrix4		smatrix4_translate(t_fvector3 p);
t_smatrix4		smatrix4_scale(t_fvector3 p);
t_smatrix4		smatrix4_rotate(t_fvector3 rad);
t_smatrix4		smatrix4_rotate_x(float rad);
t_smatrix4		smatrix4_rotate_y(float rad);
t_smatrix4		smatrix4_rotate_z(float rad);

#endif