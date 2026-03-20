/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawable_container_getters.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 02:12:57 by dzapata           #+#    #+#             */
/*   Updated: 2025/03/29 02:15:45 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/widgets.h"

long	get_actual_width(t_drawable_container *dc)
{
	return (get_widget_width(&dc->widget)
		+ dc->margin_left + dc->margin_right);
}

long	get_actual_height(t_drawable_container *dc)
{
	return (get_widget_height(&dc->widget)
		+ dc->margin_top + dc->margin_bottom);
}
