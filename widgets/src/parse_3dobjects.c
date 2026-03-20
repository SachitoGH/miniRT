/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_3dobjects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:38:57 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/25 19:25:28 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

int	preloaded(t_object3d *obj, char *str, t_scene *s)
{
	char	*end;
	char	temp;

	end = move_args(str);
	temp = *end;
	end[0] = '\0';
	if (is_texture(str, s->textures, s->amount_textures))
		obj->texture = get_texture(str, s->textures, s->amount_textures);
	else if (is_material(str, s->materials, s->amount_materials))
		obj->material = *get_material(str, s->materials, s->amount_materials);
	else if (is_pattern(str, s->patterns, s->amount_patterns))
		obj->pattern = get_pattern(str, s->patterns, s->amount_patterns);
	else
		return (end[0] = temp, NO_OBJECT_ERR);
	end[0] = temp;
	return (0);
}

int	parse_plane(t_scene *s, int index, char *str, t_objtype t)
{
	int	err;

	s->objects[index].type = t;
	parse_ftriad(&s->objects[index].position, str);
	str = skip_spaces(move_args(str));
	parse_ftriad(&s->objects[index].e_rotation, str);
	str = skip_spaces(move_args(str));
	s->objects[index].scale.x = 1;
	s->objects[index].scale.y = 1;
	s->objects[index].scale.z = 1;
	parse_color(&s->objects[index].color.rgb, str);
	str = skip_spaces(move_args(str));
	err = 0;
	default_material(&s->objects[index].material);
	while (*str && !err)
	{
		err = preloaded(&s->objects[index], str, s);
		str = skip_spaces(move_args(str));
	}
	return (err);
}

int	parse_special(t_scene *s, int index, char *str, t_objtype t)
{
	int			err;
	t_fvector3	temp;

	s->objects[index].type = t;
	parse_ftriad(&s->objects[index].position, str);
	str = skip_spaces(move_args(str));
	parse_ftriad(&s->objects[index].e_rotation, str);
	str = skip_spaces(move_args(str));
	parse_ftriad(&s->objects[index].scale, str);
	str = skip_spaces(move_args(str));
	parse_ftriad(&temp, str);
	s->objects[index].special.min = temp.x;
	s->objects[index].special.max = temp.y;
	s->objects[index].special.closed = (bool)temp.z;
	str = skip_spaces(move_args(str));
	parse_color(&s->objects[index].color.rgb, str);
	str = skip_spaces(move_args(str));
	err = 0;
	default_material(&s->objects[index].material);
	while (*str && !err)
	{
		err = preloaded(&s->objects[index], str, s);
		str = skip_spaces(move_args(str));
	}
	return (err);
}

int	parse_object(t_scene *s, int index, char *str, t_objtype t)
{
	int	err;

	s->objects[index].type = t;
	parse_ftriad(&s->objects[index].position, str);
	str = skip_spaces(move_args(str));
	parse_ftriad(&s->objects[index].e_rotation, str);
	str = skip_spaces(move_args(str));
	parse_ftriad(&s->objects[index].scale, str);
	str = skip_spaces(move_args(str));
	parse_color(&s->objects[index].color.rgb, str);
	str = skip_spaces(move_args(str));
	err = 0;
	default_material(&s->objects[index].material);
	while (*str && !err)
	{
		err = preloaded(&s->objects[index], str, s);
		str = skip_spaces(move_args(str));
	}
	return (err);
}

int	parse_light(t_scene *s, int index, char *str, t_objtype t)
{
	(void) t;
	parse_ftriad(&s->lights[index].position, str);
	str = skip_spaces(move_args(str));
	s->lights[index].brightness = ft_atof(str, DEC_SEP);
	str = skip_spaces(move_args(str));
	parse_color(&s->lights[index].color.rgb, str);
	return (0);
}
