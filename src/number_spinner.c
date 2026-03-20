/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_spinner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:13:13 by dzapata           #+#    #+#             */
/*   Updated: 2025/03/31 19:59:46 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

void	set_spinner_values(t_number_spinner *s, t_number32 low, t_number32 high,
	bool is_decimal)
{
	s->is_decimal = is_decimal;
	if (is_decimal)
	{
		s->value.decimal = 0.0f;
		s->step.decimal = CHANGE_VAL_F;
		s->low_limit.decimal = low.decimal;
		s->high_limit.decimal = high.decimal;
		s->spinner.text.text = "0.0";
	}
	else
	{
		s->value.integer = 0;
		s->step.integer = CHANGE_VAL_I;
		s->low_limit.integer = low.integer;
		s->high_limit.integer = high.integer;
		s->spinner.text.text = "0";
	}
}

//Set all atributes for a number spinner already allocated.
void	init_number_spinner(t_number_spinner *s, int x, int y, bool is_decimal)
{
	t_number32	min;
	t_number32	max;

	s->is_decimal = is_decimal;
	if (is_decimal)
	{
		min.decimal = FLT_MIN;
		max.decimal = FLT_MAX;
	}
	else
	{
		min.integer = INT_MIN;
		max.integer = INT_MAX;
	}
	set_spinner_values(s, min, max, is_decimal);
	spn_init(&s->spinner, x, y, s->spinner.text.text);
	s->spinner.text_container.widget.min_width = (15 + AMOUNT_DECIMALS)
		* WIDTH_PER_CHAR;
	spn_recalculate(&s->spinner);
}

void	draw_number_spinner_strings(t_mlx *mlx, t_image *img, void *spinner)
{
	char				buffer[BUFFER_SIZE];
	t_number_spinner	*s;

	s = (t_number_spinner *) spinner;
	if (s->is_decimal)
		ft_ftoa3(s->value.decimal, buffer, AMOUNT_DECIMALS);
	else
		ft_itoa2(s->value.integer, buffer);
	s->spinner.text.text = buffer;
	spn_draw_strings(mlx, img, &s->spinner);
}
