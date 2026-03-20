/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 07:43:57 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/27 16:52:19 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

int	control_header_strings(t_minirt *rt, t_ivector2 *point, bool draw)
{
	if (draw)
		draw_string(&rt->mlx, INIT_MSG, point, TEXT_COLOR);
	point->y += VALUES_PADDING + 20;
	if (draw)
		draw_string(&rt->mlx, WIN_WIDTH_TXT, point, TEXT_COLOR);
	point->y += TEXT_PADDING;
	if (draw)
		draw_int(rt, rt->mlx.win.width, point, TEXT_COLOR);
	point->y += VALUES_PADDING;
	if (draw)
		draw_string(&rt->mlx, WIN_HEIGHT_TXT, point, TEXT_COLOR);
	point->y += TEXT_PADDING;
	if (draw)
		draw_int(rt, rt->mlx.win.height, point, TEXT_COLOR);
	return (point->y);
}

void	draw_amounts(t_minirt *rt, t_ivector2 *point)
{
	draw_int(rt, rt->scene.amount_textures, point, TEXT_COLOR);
	point->y += TEXT_PADDING;
	draw_string(&rt->mlx, AMOUNT_LIGHTS_TXT, point, TEXT_COLOR);
	point->y += TEXT_PADDING;
	draw_int(rt, rt->scene.amount_lights, point, TEXT_COLOR);
	point->y += TEXT_PADDING;
	draw_string(&rt->mlx, AMOUNT_OBJ_TXT, point, TEXT_COLOR);
	point->y += TEXT_PADDING;
	draw_int(rt, rt->scene.amount_objects, point, TEXT_COLOR);
	point->y += TEXT_PADDING;
	draw_string(&rt->mlx, AMOUNT_MATERIALS_TXT, point, TEXT_COLOR);
	point->y += TEXT_PADDING;
	draw_int(rt, rt->scene.amount_materials, point, TEXT_COLOR);
	point->y += TEXT_PADDING;
	draw_string(&rt->mlx, AMOUNT_PATTERNS_TXT, point, TEXT_COLOR);
	point->y += TEXT_PADDING;
	draw_int(rt, rt->scene.amount_patterns, point, TEXT_COLOR);
}

void	draw_control_strings(t_minirt *rt, t_image *img)
{
	t_ivector2	point;

	point.y = INIT_TEXT_MARGINY;
	point.x = img->x + TEXT_PADDING;
	point.y = control_header_strings(rt, &point, true) + PANEL_PADDING;
	draw_rgb_panel(&rt->mlx, &point, AMB_LIGHTC_TXT, rt->spinners);
	draw_string(&rt->mlx, AMB_LIGHTB_TXT, &point, TEXT_COLOR);
	point.y += PANEL_PADDING + rt->spinners[3].spinner.widget.height;
	draw_string(&rt->mlx, FOV_TXT, &point, TEXT_COLOR);
	point.y += PANEL_PADDING + rt->spinners[4].spinner.widget.height;
	draw_string(&rt->mlx, TEXTURES_TXT, &point, TEXT_COLOR);
	point.y += TEXT_PADDING;
	draw_amounts(rt, &point);
}

void	place_control(t_minirt *rt)
{
	t_ivector2	point;

	point.y = INIT_TEXT_MARGINY;
	point.y = control_header_strings(rt, &point, false) + PANEL_PADDING;
	point.x = TEXT_PADDING + PARAM_MARGINX * 2 + WIDTH_PER_CHAR;
	point.y += VALUES_PADDING;
	point.y = place_spinner(point, 3, &rt->spinners[0]) + PANEL_PADDING;
	point.y = place_spinner(point, 1, &rt->spinners[3]) + PANEL_PADDING;
	point.y += place_spinner(point, 1, &rt->spinners[4]) + PANEL_PADDING;
}
