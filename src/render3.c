/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:08:27 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/30 15:13:07 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

t_fvector4	get_hitted(t_render_info *i, float t)
{
	return (add_vec4(i->origin, multiplyf4(i->dir, t)));
}

t_fvector4	reflect(t_fvector4 in, t_fvector4 normal)
{
	return (substract_vec4(in, multiplyf4(normal,
				2 * dot_product4(in, normal))));
}

t_fvector3	pattern_color(t_pattern *p, t_render_info *i)
{
	t_fvector4	pattern_point;

	pattern_point = smatrix4_multiply_vec4(
			&p->inverse, i->p_object);
	return (p->data->apply_at(p, pattern_point));
}
