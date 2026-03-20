/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:11:21 by dzapata           #+#    #+#             */
/*   Updated: 2025/03/31 16:43:40 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/widgets.h"
#include <stdio.h>

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

size_t	calculate_label_width(char *str)
{
	return (ft_strlen(str) * WIDTH_PER_CHAR);
}

//Draws the text of the label directly over the screen.
void	lbl_draw(t_mlx *mlx, t_image *img, void *label)
{
	t_label			*l;

	l = (t_label *) label;
	if (l->text)
	{
		if (img)
			mlx_string_put(mlx->mlx, mlx->win.ptr,
				l->widget.x + TEXT_OFFSETX + img->x,
				l->widget.y + TEXT_OFFSETY + img->y, l->color, l->text);
		else
			mlx_string_put(mlx->mlx, mlx->win.ptr, l->widget.x + TEXT_OFFSETX,
				l->widget.y + TEXT_OFFSETY, l->color, l->text);
	}
}

//Recalculates label's width
void	lbl_recalculate(t_label *l)
{
	l->widget.width = calculate_label_width(l->text);
}

//Set all atributes for a label already allocated.
void	lbl_init(t_label *l, int x, int y, char *text)
{
	l->widget.object = l;
	l->widget.draw = NULL;
	l->widget.draw_strngs = lbl_draw;
	l->widget.is_visible = true;
	l->text = text;
	l->color = DEF_TEXTCOLOR;
	l->widget.x = x;
	l->widget.y = y;
	l->widget.width = calculate_label_width(text);
	l->widget.height = HEIGHT_PER_CHAR;
	default_min_size(&l->widget);
	default_max_size(&l->widget);
}
