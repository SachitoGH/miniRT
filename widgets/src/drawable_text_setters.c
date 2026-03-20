/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawable_text_setters.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:29:39 by dzapata           #+#    #+#             */
/*   Updated: 2025/03/29 01:47:30 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/widgets.h"

void	drwtext_set_halignment(t_drawable_text *t, char hal)
{
	t->alignment = (t->alignment & VAL_MASK) | (hal & HAL_MASK);
}

void	drwtext_set_valignment(t_drawable_text *t, char val)
{
	t->alignment = (val & VAL_MASK) | (t->alignment & HAL_MASK);
}
