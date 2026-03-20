/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 01:58:33 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/30 04:22:31 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

void	select_object(t_minirt *rt, int x, int y)
{
	t_render_info	info;
	int				hitted;
	int				i;

	info.origin = rt->scene.camera.origin;
	info.dir = ray_for_pixel(&rt->scene.camera,
			x - rt->render.x, y - rt->render.y);
	hitted = hit_objects(&rt->scene, &info);
	if (!hitted)
		return ;
	sort_data(rt->scene.depth, hitted);
	i = 0;
	while (i < hitted && rt->scene.depth[i].t < F_EPSILON)
		i++;
	if (i == hitted)
		return ;
	rt->elem = rt->scene.depth[i].obj;
	rt->elem_select = OBJECT;
	link_object(rt);
	place_general(rt);
	set_background(&rt->general, rt->general.bg_color);
	draw_image_window(&rt->mlx, &rt->general);
	draw_general_strings(rt, &rt->general);
}
