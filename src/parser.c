/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 23:06:16 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/30 04:46:06 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

int	manage_preload_objects(t_text *text, t_mlx *mlx, t_scene *s,
	t_def_obj_data *data)
{
	t_parser	p;

	p = (t_parser){0};
	p.temp = text->data;
	while (p.temp)
	{
		p.str = skip_spaces((char *) p.temp->content);
		p.obj = get_object_by_str(p.str, data);
		if (p.obj->e_type == TEXTURE || p.obj->e_type == MATERIAL
			|| p.obj->e_type == PATTERN)
		{
			p.err = p.obj->parse(s, p.n_init[p.obj->e_type]++,
					skip_spaces(move_arg(p.str)), p.obj->o_type);
			if (p.err)
				return (p.err);
			if (p.obj->e_type == TEXTURE && !new_texture(mlx,
					&s->textures[p.n_init[p.obj->e_type] - 1],
					skip_spaces(move_args(skip_spaces(move_args(p.str))))))
				return (TEXTURE_ERR);
		}
		p.temp = p.temp->next;
	}
	return (0);
}

int	manage_objects(t_text *text, t_scene *s, t_def_obj_data *data)
{
	t_parser	p;

	p = (t_parser){0};
	p.temp = text->data;
	while (p.temp)
	{
		p.str = skip_spaces((char *) p.temp->content);
		p.obj = get_object_by_str(p.str, data);
		if (p.obj->e_type != TEXTURE && p.obj->e_type != MATERIAL
			&& p.obj->e_type != PATTERN)
		{
			s->objects[p.n_init[p.obj->e_type]].data = p.obj;
			p.err = p.obj->parse(s, p.n_init[p.obj->e_type]++,
					skip_spaces(move_arg(p.str)), p.obj->o_type);
			if (p.err)
				return (p.err);
		}
		p.temp = p.temp->next;
	}
	return (0);
}

int	preload_objects(t_mlx *mlx, t_scene *s, t_text *file, t_def_obj_data *data)
{
	if (s->amount_textures > 0)
	{
		s->textures = ft_calloc(s->amount_textures, sizeof(t_texture));
		if (!s->textures)
			return (MALLOC_ERR);
	}
	if (s->amount_materials > 0)
	{
		s->materials = ft_calloc(s->amount_materials, sizeof(t_material));
		if (!s->materials)
			return (MALLOC_ERR);
	}
	if (s->amount_patterns > 0)
	{
		s->patterns = ft_calloc(s->amount_patterns, sizeof(t_pattern));
		if (!s->patterns)
			return (MALLOC_ERR);
	}
	if (s->amount_textures > 0 || s->amount_materials > 0
		|| s->amount_patterns > 0)
		return (manage_preload_objects(file, mlx, s, data));
	return (0);
}

// Parses an already verified .rt file.
int	parse_rt_file(t_mlx *mlx, t_scene *s, t_text *file, t_def_obj_data *data)
{
	int	err;

	err = preload_objects(mlx, s, file, data);
	if (err)
		return (err);
	if (s->amount_objects > 0)
	{
		s->depth = ft_calloc(s->depth_count, sizeof(t_object_data));
		if (!s->depth)
			return (MALLOC_ERR);
		s->objects = ft_calloc(s->amount_objects, sizeof(t_object3d));
		if (!s->objects)
			return (MALLOC_ERR);
	}
	if (s->amount_lights > 0)
	{
		s->lights = ft_calloc(s->amount_lights, sizeof(t_light));
		if (!s->lights)
			return (MALLOC_ERR);
	}
	return (manage_objects(file, s, data));
}
