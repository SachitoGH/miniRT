/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_odata.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 04:32:50 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/26 17:21:34 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

void	default_material(t_material *m)
{
	m->id[0] = '\0';
	m->ambient = 1;
	m->diffuse = 0.9;
	m->specular = 0.9f;
	m->reflective = 0;
	m->refractive = 0;
	m->shininess = 200;
	m->transparence = 0;
}

void	init_def_data_obj(t_def_obj_data *data)
{
	data[0] = (t_def_obj_data){CAMERA_ID, verify_camera, parse_camera,
		NULL, NULL, OTHER, UNKNOWN, 0, 0};
	data[1] = (t_def_obj_data){AMB_LIGHT_ID, verify_amb_light, parse_amb_light,
		NULL, NULL, OTHER, UNKNOWN, 0, 0};
	data[2] = (t_def_obj_data){LIGHT_ID, verify_light, parse_light,
		NULL, NULL, LIGHT, UNKNOWN, 0, 0};
	data[3] = (t_def_obj_data){TEXTURE_ID, verify_texture, parse_texture,
		NULL, NULL, TEXTURE, UNKNOWN, 0, 0};
	data[4] = (t_def_obj_data){MATERIAL_ID, verify_material, parse_material,
		NULL, NULL, MATERIAL, UNKNOWN, 0, 0};
	data[5] = (t_def_obj_data){PATTERN_ID, verify_pattern, parse_pattern,
		NULL, NULL, PATTERN, UNKNOWN, 0, 0};
	data[6] = (t_def_obj_data){PLANE_ID, verify_plane, parse_plane,
		hit_plane, normal_plane, OBJECT, PLANE, 1, 0};
	data[7] = (t_def_obj_data){CYLINDER_ID, verify_special, parse_special,
		hit_cylinder, normal_cylinder, OBJECT, CYLINDER, 4, 0};
	data[8] = (t_def_obj_data){ELLIPSOID_ID, verify_object, parse_object,
		hit_ellipsoid, normal_ellipsoid, OBJECT, ELLIPSOID, 2, 0};
	data[9] = (t_def_obj_data){CONOID_ID, verify_special, parse_special,
		hit_conoid, normal_conoid, OBJECT, CONOID, 4, 0};
	data[10] = (t_def_obj_data){CUBOID_ID, verify_object, parse_object,
		hit_cuboid, normal_cuboid, OBJECT, CUBOID, 2, 0};
}

t_def_obj_data	*get_object_by_str(char *str, t_def_obj_data *obj)
{
	int		i;
	size_t	len;

	i = -1;
	len = move_args(str) - str;
	if (len > OBJ_MAX_LEN)
		return (NULL);
	while (++i < N_OBJ_FILE)
	{
		if (!ft_strncmp(str, obj[i].str, len))
			return (&obj[i]);
	}
	return (NULL);
}

t_def_obj_data	*get_object_by_type(t_objtype type, t_def_obj_data *obj)
{
	int		i;

	i = -1;
	while (++i < N_OBJ_FILE)
	{
		if (type == obj[i].o_type)
			return (&obj[i]);
	}
	return (NULL);
}
