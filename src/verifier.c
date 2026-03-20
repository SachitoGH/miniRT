/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifier.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:59:28 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/27 17:09:48 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

int	verify_integrity(t_scene *s, char *str, t_def_obj_data *data)
{
	t_def_obj_data	*obj;

	obj = get_object_by_str(str, data);
	if (!obj)
		return (UNKNOWN_OBJ_ERR);
	if (obj->has_init && ft_strlen(obj->str) < 2 && ft_isuppercase(obj->str[0]))
		return (MULTI_INIT_ERR);
	obj->has_init = true;
	str = skip_spaces(str + ft_strlen(obj->str));
	if (obj->e_type == LIGHT)
		s->amount_lights++;
	else if (obj->e_type == TEXTURE)
		s->amount_textures++;
	else if (obj->e_type == OBJECT)
	{
		s->amount_objects++;
		s->depth_count += obj->max_intersect;
	}
	else if (obj->e_type == MATERIAL)
		s->amount_materials++;
	else if (obj->e_type == PATTERN)
		s->amount_patterns++;
	return (obj->verify(str));
}

int	verify_content(t_text *text, t_scene *s, t_def_obj_data *data)
{
	char	*str;
	int		i;
	int		err;
	t_list	*temp;

	i = -1;
	temp = text->data;
	while (++i < text->lines)
	{
		str = skip_spaces((char *) temp->content);
		if (str)
		{
			err = verify_integrity(s, str, data);
			if (err)
				return (err);
		}
		temp = temp->next;
	}
	if (!get_object_by_str(CAMERA_ID, data)->has_init)
		return (NO_CAMERA_ERR);
	return (0);
}

int	verify_basics(char **str)
{
	int	err;

	err = verify_position(str);
	if (err)
		return (err);
	err = verify_values(str, 3, 0, true);
	if (err)
		return (err);
	err = verify_values(str, 3, 2, true);
	if (err)
		return (err);
	return (verify_color(str));
}
