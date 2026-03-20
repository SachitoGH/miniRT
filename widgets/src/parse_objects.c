/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:31:47 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/30 04:46:29 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

int	parse_camera(t_scene *s, int index, char *str, t_objtype t)
{
	(void) index;
	(void) t;
	parse_ftriad(&s->camera.position, str);
	str = skip_spaces(move_args(str));
	parse_ftriad(&s->camera.forward, str);
	str = skip_spaces(move_args(str));
	s->camera.viewport.fov = ft_atoi(str);
	return (0);
}

int	parse_amb_light(t_scene *s, int index, char *str, t_objtype t)
{
	(void) index;
	(void) t;
	s->camera.alight_brightness = ft_atof(str, DEC_SEP);
	str = skip_spaces(move_args(str));
	parse_color(&s->camera.alight_color.rgb, str);
	return (0);
}

int	parse_texture(t_scene *s, int index, char *str, t_objtype t)
{
	size_t	len;

	(void) t;
	len = 0;
	if (!verify_unique_id(str, s, &len))
		return (REPEATED_ID_ERR);
	ft_strlcpy(s->textures[index].id, str, len + 1);
	return (0);
}

int	parse_material(t_scene *s, int index, char *str, t_objtype t)
{
	size_t		len;
	t_fvector3	temp;

	(void) t;
	len = 0;
	if (!verify_unique_id(str, s, &len))
		return (REPEATED_ID_ERR);
	ft_strlcpy(s->materials[index].id, str, len + 1);
	len = ft_strlen(ARGS_SEP);
	str = skip_spaces(move_arg(str));
	parse_ftriad(&temp, str);
	s->materials[index].diffuse = temp.x;
	s->materials[index].specular = temp.y;
	s->materials[index].ambient = temp.z;
	str = move_arg(str) + len;
	parse_ftriad(&temp, str);
	s->materials[index].transparence = temp.x;
	str = move_arg(move_arg(move_arg(str) + len) + len) + len;
	parse_ftriad(&temp, str);
	s->materials[index].reflective = temp.x;
	s->materials[index].refractive = temp.y;
	s->materials[index].shininess = temp.z;
	return (0);
}

int	parse_pattern(t_scene *s, int index, char *str, t_objtype t)
{
	t_def_pat_data	patterns[N_PATTERNS];
	size_t			len;

	(void) t;
	len = 0;
	if (!verify_unique_id(str, s, &len))
		return (REPEATED_ID_ERR);
	ft_strlcpy(s->patterns[index].id, str, len + 1);
	str = skip_spaces(move_arg(str));
	init_def_pat_data(patterns);
	s->patterns[index].type = get_pattern_by_str(str, patterns)->type;
	str = skip_spaces(move_arg(str));
	parse_ftriad(&s->patterns[index].position, str);
	str = skip_spaces(move_args(str));
	parse_ftriad(&s->patterns[index].rotation, str);
	str = skip_spaces(move_args(str));
	parse_ftriad(&s->patterns[index].scale, str);
	str = skip_spaces(move_args(str));
	parse_color(&s->patterns[index].color_a.rgb, str);
	str = skip_spaces(move_args(str));
	parse_color(&s->patterns[index].color_b.rgb, str);
	return (0);
}
