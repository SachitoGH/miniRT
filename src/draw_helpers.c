/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:51:41 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/27 16:52:39 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

void	draw_axis_panel(t_mlx *mlx, t_ivector2 *point, char *panel,
	t_number_spinner *params)
{
	draw_string(mlx, panel, point, TEXT_COLOR);
	draw_triads_strings(mlx, point, (char *[3]){"X", "Y", "Z"}, params);
}

void	draw_rgb_panel(t_mlx *mlx, t_ivector2 *point, char *panel,
	t_number_spinner *params)
{
	draw_string(mlx, panel, point, TEXT_COLOR);
	draw_triads_strings(mlx, point, (char *[3]){"R", "G", "B"}, params);
}

int	place_spinner(t_ivector2 init_point, int n, t_number_spinner *params)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		spn_set_x(&params[i].spinner, init_point.x);
		spn_set_y(&params[i].spinner, init_point.y);
		init_point.y += params[i].spinner.widget.height;
	}
	return (init_point.y);
}

void	draw_triads_strings(t_mlx *mlx, t_ivector2 *points, char *textes[3],
	t_number_spinner *spinner)
{
	t_ivector2	point;
	short		i;

	point.x = points->x + PARAM_MARGINX;
	i = -1;
	while (++i < 3)
	{
		point.y = spinner[i].spinner.widget.y
			+ spinner[i].spinner.text_container.margin_top;
		draw_string(mlx, textes[i], &point, TEXT_COLOR);
	}
	points->y = spinner[i - 1].spinner.widget.y
		+ spinner[i - 1].spinner.widget.height
		+ spinner[i - 1].spinner.text_container.margin_top;
}
