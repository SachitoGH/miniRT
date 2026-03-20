/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_strings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 22:33:53 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/18 21:42:14 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

char	*get_element_type(t_element type, void *elem)
{
	t_object3d	*obj;

	if (type == OBJECT)
	{
		obj = (t_object3d *) elem;
		if (obj->type == PLANE)
			return (PLANE_TXT);
		else if (obj->type == ELLIPSOID)
			return (ELLIPSOID_TXT);
		else if (obj->type == CUBOID)
			return (CUBOID_TXT);
		else if (obj->type == CONOID)
			return (CONOID_TXT);
		else if (obj->type == CYLINDER)
			return (CYLINDER_TXT);
	}
	else if (type == LIGHT)
		return (LIGHT_TXT);
	return (UNKNOWN_ELEMENT);
}
