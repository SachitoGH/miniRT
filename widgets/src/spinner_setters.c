/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spinner_setters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:35:12 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/27 15:49:59 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/widgets.h"
#include <stdio.h>

void	spn_set_x(t_spinner *s, int x)
{
	btn_set_x(&s->decrease, x);
	s->text_container.widget.x += x - s->widget.x;
	btn_set_x(&s->increase, s->text_container.widget.x + 1
		+ get_actual_width(&s->text_container));
	s->widget.x = x;
}

void	spn_set_y(t_spinner *s, int y)
{
	btn_set_y(&s->decrease, y);
	s->text_container.widget.y += y - s->widget.y;
	btn_set_y(&s->increase, s->text_container.widget.y);
	s->widget.y = y;
}
