/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spinner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 00:48:49 by dzapata           #+#    #+#             */
/*   Updated: 2025/03/31 20:31:43 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/widgets.h"

//Draws the text of the spinner, as well as the text of the buttons
void	spn_draw_strings(t_mlx *mlx, t_image *img, void *spinner)
{
	t_spinner	*s;

	s = (t_spinner *) spinner;
	s->decrease.widget.draw_strngs(mlx, img, &s->decrease);
	drwcontainer_draw_string(mlx, img, &s->text, &s->text_container);
	s->increase.widget.draw_strngs(mlx, img, &s->increase);
}

//Draws the spinner in the form of | Button | Label | Button |
void	spn_draw(t_image *img, void *spinner)
{
	t_spinner		*s;

	s = (t_spinner *) spinner;
	s->decrease.widget.draw(img, s->decrease.widget.object);
	s->text_container.widget.draw(img, s->text_container.widget.object);
	s->increase.widget.draw(img, s->increase.widget.object);
}

//Recalculates the label and increment button sizes and positions
void	spn_recalculate(t_spinner *s)
{
	btn_recalculate(&s->decrease);
	s->text_container.widget.x = s->decrease.widget.x + 1
		+ get_actual_width(&s->decrease.text_container);
	s->text_container.widget.y = s->decrease.widget.y;
	s->text_container.widget.width = calculate_label_width(s->text.text);
	s->text_container.widget.height = HEIGHT_PER_CHAR;
	btn_init(&s->increase, s->text_container.widget.x + 1
		+ get_actual_width(&s->text_container), s->decrease.widget.y,
		s->increase.text.text);
	btn_recalculate(&s->increase);
	s->widget.width = s->increase.widget.width + s->decrease.widget.width
		+ s->text_container.widget.width + 2;
	s->widget.height = s->increase.widget.height + s->decrease.widget.height
		+ s->text_container.widget.height;
}

//Set all atributes for a spinner already allocated.
void	spn_init(t_spinner *s, int x, int y, char *text)
{
	s->widget.draw = spn_draw;
	s->widget.draw_strngs = spn_draw_strings;
	s->widget.object = s;
	s->widget.is_visible = true;
	s->widget.x = x;
	s->widget.y = y;
	default_min_size(&s->widget);
	default_max_size(&s->widget);
	drwtext_init(&s->text, text, DEF_TEXTCOLOR, HAL_CENTER | VAL_CENTER);
	btn_init(&s->decrease, x, y, DEC_BTN_TEXT);
	drwcontainer_init(&s->text_container,
		(t_ivector2){s->decrease.widget.x + 1
		+ get_actual_width(&s->decrease.text_container), s->decrease.widget.y},
		(t_ivector2){calculate_label_width(text), HEIGHT_PER_CHAR});
	btn_init(&s->increase, s->text_container.widget.x + 1
		+ get_actual_width(&s->text_container), s->decrease.widget.y,
		INC_BTN_TEXT);
	s->widget.width = s->increase.widget.width + s->decrease.widget.width
		+ s->text_container.widget.width + 2;
	s->widget.height = s->increase.widget.height + s->decrease.widget.height
		+ s->text_container.widget.height;
}
