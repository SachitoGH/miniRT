/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel_general.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 20:20:42 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/27 16:52:02 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

int	general_header_strings(t_minirt *rt, t_ivector2 point, bool draw)
{
	if (draw)
		draw_string(&rt->mlx, OBJ_TYPE_TXT, &point, TEXT_COLOR);
	point.y += VALUES_PADDING;
	if (draw)
		draw_string(&rt->mlx, get_element_type(rt->elem_select, rt->elem),
			&point, TEXT_COLOR);
	return (point.y);
}

void	draw_general_strings(t_minirt *rt, t_image *img)
{
	t_ivector2	point;

	point.y = INIT_TEXT_MARGINY;
	point.x = img->x + TEXT_PADDING;
	if (rt->elem)
	{
		point.y = general_header_strings(rt, point, true) + PANEL_PADDING;
		draw_axis_panel(&rt->mlx, &point, POSITION_TXT, &rt->spinners[5]);
		if (rt->elem_select == OBJECT)
		{
			draw_axis_panel(&rt->mlx, &point, ROTATION_TXT, &rt->spinners[8]);
			draw_axis_panel(&rt->mlx, &point, SCALE_TXT, &rt->spinners[11]);
		}
		draw_rgb_panel(&rt->mlx, &point, COLOR_TXT, &rt->spinners[14]);
	}
}

void	place_general(t_minirt *rt)
{
	t_ivector2	point;
	int			i;

	point.y = INIT_TEXT_MARGINY;
	point.x = TEXT_PADDING + PARAM_MARGINX * 2 + WIDTH_PER_CHAR;
	point.y = general_header_strings(rt, point, false)
		+ PANEL_PADDING + VALUES_PADDING;
	point.y = place_spinner(point, 3, &rt->spinners[5]) + PANEL_PADDING;
	if (rt->elem_select == OBJECT)
	{
		point.y = place_spinner(point, 3, &rt->spinners[8]) + PANEL_PADDING;
		point.y = place_spinner(point, 3, &rt->spinners[11]) + PANEL_PADDING;
	}
	i = 7;
	while (++i < 15)
		rt->spinners[i].spinner.widget.is_visible = (rt->elem_select == OBJECT);
	point.y = place_spinner(point, 3, &rt->spinners[14]) + PANEL_PADDING;
}
