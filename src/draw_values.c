/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 03:51:21 by dzapata           #+#    #+#             */
/*   Updated: 2025/03/31 22:33:29 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

void	draw_bool(t_mlx *mlx, bool b, t_ivector2 *point, int color)
{
	char	*temp;

	if (b)
		temp = TRUE_TXT;
	else
		temp = FALSE_TXT;
	draw_string(mlx, temp, point, color);
}

void	draw_int(t_minirt *rt, int number, t_ivector2 *point, int color)
{
	ft_itoa2(number, rt->str_buffer);
	draw_string(&rt->mlx, rt->str_buffer, point, color);
}

void	draw_float(t_minirt *rt, float number, t_ivector2 *point, int color)
{
	ft_ftoa3(number, rt->str_buffer, AMOUNT_DECIMALS);
	draw_string(&rt->mlx, rt->str_buffer, point, color);
}

void	draw_double(t_minirt *rt, double number, t_ivector2 *point,
	int color)
{
	ft_dtoa3(number, rt->str_buffer, AMOUNT_DECIMALS);
	draw_string(&rt->mlx, rt->str_buffer, point, color);
}

void	draw_string(t_mlx *mlx, char *str, t_ivector2 *point, int color)
{
	mlx_string_put(mlx->mlx, mlx->win.ptr, point->x + TEXT_OFFSETX,
		point->y + TEXT_OFFSETY, color, str);
}
