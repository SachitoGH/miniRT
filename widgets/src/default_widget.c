/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_widget.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:41:13 by dzapata           #+#    #+#             */
/*   Updated: 2025/03/25 18:46:21 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/widgets.h"

void	default_min_size(t_widget *w)
{
	w->min_width = DEF_MIN_WIDTH;
	w->min_height = DEF_MIN_HEIGHT;
}

void	default_max_size(t_widget *w)
{
	w->max_width = DEF_MAX_WIDTH;
	w->max_height = DEF_MAX_HEIGHT;
}
