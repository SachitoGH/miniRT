/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_camera.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:14:15 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/28 20:08:40 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

void	calculate_objects_camera(t_scene *s)
{
	int	i;

	i = -1;
	while (++i < s->amount_objects)
		calculate_object(&s->objects[i], &s->camera);
	i = -1;
	while (++i < s->amount_patterns)
		calculate_pattern(&s->patterns[i], &s->camera);
}

void	camera_transform(t_camera *c)
{
	t_smatrix4	temp;

	c->transform = smatrix4_identity();
	c->transform.data[0][0] = c->right.x;
	c->transform.data[0][1] = c->right.y;
	c->transform.data[0][2] = c->right.z;
	c->transform.data[1][0] = c->up.x;
	c->transform.data[1][1] = c->up.y;
	c->transform.data[1][2] = c->up.z;
	c->transform.data[2][0] = -c->forward.x;
	c->transform.data[2][1] = -c->forward.y;
	c->transform.data[2][2] = -c->forward.z;
	c->transform = smatrix4_multiply(&c->transform, &c->rotation);
	temp = smatrix4_translate(negate(c->position));
	c->transform = smatrix4_multiply(&c->transform, &temp);
	c->inverse = smatrix4_inverse(&c->transform);
	c->origin = smatrix4_multiply_vec4(&c->inverse, point(0, 0, 0));
}

void	calculate_camera(t_camera *c, t_image *img)
{
	float		half_view;
	t_fvector3	def_up;

	c->viewport.aspect_ratio = img->width / (float) img->height;
	half_view = tanf(c->viewport.fov * (DEG_RADIANTS * 0.5));
	if (c->viewport.aspect_ratio >= 1.0f)
	{
		c->viewport.half_width = half_view;
		c->viewport.half_height = half_view / c->viewport.aspect_ratio;
	}
	else
	{
		c->viewport.half_width = half_view * c->viewport.aspect_ratio;
		c->viewport.half_height = half_view;
	}
	c->viewport.pixel_size = (c->viewport.half_width * 2) / img->width;
	def_up = (t_fvector3){0.0f, 1.0f, 0.0f};
	c->forward = normalize(c->forward);
	c->right = normalize(cross_product(c->forward, def_up));
	c->up = normalize(cross_product(c->right, c->forward));
	c->rotation = smatrix4_identity();
	camera_transform(c);
}
