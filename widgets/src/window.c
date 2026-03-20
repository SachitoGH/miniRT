/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:07:22 by dzapata           #+#    #+#             */
/*   Updated: 2025/03/31 21:55:02 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/widgets.h"

//Creates a new window. If allocation fails, set the ptr attribute to NULL
t_window	new_window(void *mlx, int width, int height, char *title)
{
	t_window	win;

	win.ptr = mlx_new_window(mlx, width, height, title);
	if (!win.ptr)
	{
		win.width = 0;
		win.height = 0;
	}
	win.width = width;
	win.height = height;
	return (win);
}
