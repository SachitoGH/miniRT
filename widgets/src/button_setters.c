/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_setters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 03:31:50 by dzapata           #+#    #+#             */
/*   Updated: 2025/03/29 03:34:21 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/widgets.h"

void	btn_set_x(t_button *b, int x)
{
	b->text_container.widget.x = x;
	b->widget.x = x;
}

void	btn_set_y(t_button *b, int y)
{
	b->text_container.widget.y = y;
	b->widget.x = y;
}
