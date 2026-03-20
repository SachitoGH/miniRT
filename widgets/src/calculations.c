/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 02:22:48 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/30 04:53:58 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

static t_smatrix4	transform_matrix(t_fvector3 camera_p, t_fvector3 position,
	t_fvector3 e_rotation, t_fvector3 scale)
{
	t_smatrix4	matrix;
	t_smatrix4	temp;

	matrix = smatrix4_scale(scale);
	temp = smatrix4_rotate(euler_to_radiants(e_rotation));
	matrix = smatrix4_multiply(&temp, &matrix);
	temp = smatrix4_translate(position);
	matrix = smatrix4_multiply(&temp, &matrix);
	temp = smatrix4_translate(negate(camera_p));
	matrix = smatrix4_multiply(&temp, &matrix);
	return (matrix);
}

void	calculate_object(t_object3d *o, t_camera *c)
{
	o->color.normalized = normalize_color(o->color.rgb);
	o->scale = abs_vec(o->scale);
	o->transform = transform_matrix(c->position,
			o->position, o->e_rotation, o->scale);
	o->inverse = smatrix4_inverse(&o->transform);
	o->l_origin = smatrix4_multiply_vec4(&o->inverse, c->origin);
	o->transpose = smatrix4_transpose(&o->inverse);
}

void	calculate_pattern(t_pattern *p, t_camera *c)
{
	p->transform = transform_matrix(c->position, p->position,
			p->rotation, p->scale);
	p->inverse = smatrix4_inverse(&p->transform);
	p->color_a.normalized = normalize_color(p->color_a.rgb);
	p->color_b.normalized = normalize_color(p->color_b.rgb);
}

void	calculate_light(t_light *l)
{
	l->color.normalized = normalize_color(l->color.rgb);
	l->color_attenuated = multiplyf(l->color.normalized, l->brightness);
}

void	calculus(t_scene *s)
{
	int	i;

	i = -1;
	while (++i < s->amount_objects)
		calculate_object(&s->objects[i], &s->camera);
	i = -1;
	while (++i < s->amount_lights)
		calculate_light(&s->lights[i]);
	i = -1;
	while (++i < s->amount_patterns)
		calculate_pattern(&s->patterns[i], &s->camera);
	s->camera.alight_color.normalized = normalize_color(
			s->camera.alight_color.rgb);
}
