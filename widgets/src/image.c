/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 02:21:55 by dzapata           #+#    #+#             */
/*   Updated: 2025/04/13 19:57:17 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/widgets.h"

//Creates a new image. if allocation fails, the ptr attribute is set to NULL
t_image	new_image(void *mlx, t_ivector2 size, int bg_color,
	unsigned int amount_widgets)
{
	t_image	img;

	img = (t_image){0};
	if (amount_widgets > 0)
	{
		img.widgets = malloc(sizeof(t_widget *) * amount_widgets);
		if (!img.widgets)
			return (img);
	}
	img.ptr = mlx_new_image(mlx, size.x, size.y);
	if (img.ptr)
	{
		img.width = size.x;
		img.height = size.y;
		img.addr = mlx_get_data_addr (img.ptr, (int *) &img.bits_per_pixel,
				(int *) &img.line_length, (int *) &img.endian);
		img.bg_color = bg_color;
		img.amount_wigets = amount_widgets;
		return (img);
	}
	free(img.widgets);
	img.widgets = NULL;
	return (img);
}

// Destroy the ptr of the image and free the array of widgets
void	destroy_image(void *mlx, t_image *img)
{
	if (img && img->ptr)
	{
		mlx_destroy_image(mlx, img->ptr);
		free(img->widgets);
		img->widgets = NULL;
	}
}

//Puts a pixel over an image
inline void	put_pixel_image(t_image *data, int x, int y, int color)
{
	*(unsigned int *)(data->addr + (y * data->line_length
				+ x * (data->bits_per_pixel / 8))) = color;
}

//Paints the background of an image to the given color
void	set_background(t_image *image, int color)
{
	unsigned int	i;
	unsigned int	j;
	int				*dst;

	i = 0;
	while (i < image->height)
	{
		dst = (int *)(image->addr + i * image->line_length);
		j = 0;
		while (j < image->width)
			dst[j++] = color;
		i++;
	}
}
