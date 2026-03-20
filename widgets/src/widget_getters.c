/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   widgets_getters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:08:11 by dzapata           #+#    #+#             */
/*   Updated: 2025/03/27 19:08:27 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/widgets.h"

unsigned int	get_widget_width(t_widget *w)
{
	if (w->width < w->min_width)
		return (w->min_width);
	else if (w->width > w->max_width)
		return (w->max_width);
	return (w->width);
}

unsigned int	get_widget_height(t_widget *w)
{
	if (w->height < w->min_height)
		return (w->min_height);
	else if (w->height > w->max_height)
		return (w->max_height);
	return (w->height);
}
