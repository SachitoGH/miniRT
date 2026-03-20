/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:10:54 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/30 15:13:16 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

t_fvector3	lightning(t_object_data *o, t_render_info *info, t_light *l)
{
	t_fvector3	color;
	t_fvector3	diffuse;
	t_fvector3	specular;
	float		dot_temp;

	dot_temp = dot_product4(info->light_dir, info->normal);
	if (dot_temp < F_EPSILON)
		return ((t_fvector3){0, 0, 0});
	color = multiply_vec(info->color, l->color_attenuated);
	color = multiply_vec(color, l->color_attenuated);
	diffuse = multiplyf(color, o->obj->material.diffuse * dot_temp);
	dot_temp = dot_product4(reflect(negate4(info->light_dir),
				info->normal), info->eye);
	if (dot_temp <= F_EPSILON)
		specular = (t_fvector3){0, 0, 0};
	else
		specular = multiplyf(l->color.normalized, o->obj->material.specular
				* powf(dot_temp, o->obj->material.shininess));
	return (add_vec(diffuse, specular));
}

bool	is_valid_hit(t_render_info *info, float magnitude)
{
	int	i;

	i = 0;
	while (i < info->n_hits && (info->t[i] <= F_EPSILON
			|| info->t[i] > magnitude))
		i++;
	return (i != info->n_hits);
}

bool	is_shadowed(t_scene *s, t_render_info *info, t_light *l)
{
	int				i;
	float			magnitude;
	t_render_info	temp;

	i = -1;
	info->light_dir = substract_vec4(to_point4(l->position), info->p_moved);
	magnitude = get_length4(info->light_dir);
	info->light_dir = normalize4(info->light_dir);
	while (++i < s->amount_objects)
	{
		if (s->objects[i].data->hit(&s->objects[i],
				smatrix4_multiply_vec4(&s->objects[i].inverse, info->light_dir),
				smatrix4_multiply_vec4(&s->objects[i].inverse, info->p_moved),
				&temp) && is_valid_hit(&temp, magnitude))
			return (true);
	}
	return (false);
}

int	shade_point(t_scene *s, t_render_info *info, int i)
{
	int			j;
	t_fvector3	color;

	j = -1;
	if (s->depth[i].obj->pattern)
		info->color = pattern_color(s->depth[i].obj->pattern, info);
	else
		info->color = s->depth[i].obj->color.normalized;
	color = multiply_vec(info->color, info->ambient);
	color = multiplyf(color, s->depth[i].obj->material.ambient);
	while (++j < s->amount_lights)
		if (!is_shadowed(s, info, &s->lights[j]))
			color = add_vec(color, lightning(&s->depth[i],
						info, &s->lights[j]));
	return (normalized_to_rgb(color));
}

int	hit_objects(t_scene *s, t_render_info *info)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = 0;
	while (++i < s->amount_objects)
	{
		if (s->objects[i].data->hit(&s->objects[i],
				smatrix4_multiply_vec4(&s->objects[i].inverse, info->dir),
				s->objects[i].l_origin, info))
		{
			k = -1;
			while (++k < info->n_hits)
			{
				s->depth[j].t = info->t[k];
				s->depth[j++].obj = &s->objects[i];
			}
		}
	}
	return (j);
}
