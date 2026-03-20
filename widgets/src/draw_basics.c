/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_basics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 07:16:47 by dzapata           #+#    #+#             */
/*   Updated: 2025/03/31 20:31:43 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/widgets.h"

void	draw_hline(t_image *img, t_ivector2 *a, int final_x, int color)
{
	long	i;
	long	j;
	int		*dst;

	i = MIN(a->x, final_x);
	if (i > img->width || (long) a->y > img->height || a->y < 0)
		return ;
	j = MIN((long) MAX(a->x, final_x), (long) img->width);
	i = MAX(i, 0);
	dst = (int *)(img->addr + a->y * img->line_length);
	while (i < j)
		dst[i++] = color;
}

void	draw_vline(t_image *img, t_ivector2 *a, int final_y, int color)
{
	long	i;
	long	j;

	i = MIN(a->y, final_y);
	if (i > img->height || (long) a->x > img->width || a->x < 0)
		return ;
	j = MIN((long) MAX(a->y, final_y), (long) img->height);
	i = MAX(i, 0);
	while (i < j)
		*(unsigned int *)(img->addr + ((i++) * img->line_length
					+ a->x * (img->bits_per_pixel / 8))) = color;
}

//Draws a square over the given image
void	draw_square(t_image *img, t_ivector2 points[2], int color, bool fill)
{
	t_ivector2	temp;

	draw_hline(img, &points[0], points[1].x, color);
	temp.x = points[0].x;
	temp.y = points[0].y;
	if (fill)
	{
		while (++temp.y < points[1].y - 1)
			draw_hline(img, &temp, points[1].x, color);
	}
	else
		temp.y = points[1].y - 1;
	draw_vline(img, &points[0], points[1].y, color);
	draw_vline(img, &points[1], points[0].y, color);
	draw_hline(img, &temp, points[1].x, color);
}
