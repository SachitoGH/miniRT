/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:25:38 by dzapata           #+#    #+#             */
/*   Updated: 2025/03/31 20:31:43 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/widgets.h"

//Draws the text of the button directly over the screen.
void	btn_draw_strings(t_mlx *mlx, t_image *img, void *button)
{
	t_button		*b;

	b = (t_button *) button;
	drwcontainer_draw_string(mlx, img, &b->text, &b->text_container);
}

//Draws the square who represents the button.
void	btn_draw(t_image *img, void *button)
{
	t_button		*b;

	b = (t_button *) button;
	b->text_container.widget.draw(img, b->text_container.widget.object);
}

//Recalculates the size of the button, as well as the text
void	btn_recalculate(t_button *b)
{
	b->widget.width = calculate_label_width(b->text.text);
	b->widget.height = HEIGHT_PER_CHAR;
	b->text_container.widget.width = b->widget.width;
	b->text_container.widget.height = b->widget.height;
}

//Set all atributes for a button already allocated.
void	btn_init(t_button *b, int x, int y, char *text)
{
	b->widget.draw = btn_draw;
	b->widget.draw_strngs = btn_draw_strings;
	b->widget.object = b;
	b->widget.x = x;
	b->widget.y = y;
	b->widget.is_visible = true;
	b->is_enabled = true;
	b->onclick = NULL;
	b->widget.width = calculate_label_width(text);
	b->widget.height = HEIGHT_PER_CHAR;
	drwtext_init(&b->text, text, DEF_TEXTCOLOR, HAL_CENTER | VAL_CENTER);
	drwcontainer_init(&b->text_container, (t_ivector2){x, y},
		(t_ivector2){b->widget.width, b->widget.height});
	default_min_size(&b->widget);
	default_max_size(&b->widget);
}
