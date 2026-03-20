/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:19:06 by dzapata           #+#    #+#             */
/*   Updated: 2025/03/31 21:54:33 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/widgets.h"

//Creates a new mlx variable and a window. If allocation fails the mlx field
//and the win.ptr field are set to NULL
t_mlx	create_mlx(int window_width, int window_height, char *window_title)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		return (mlx.win.ptr = NULL, mlx);
	mlx.win = new_window(mlx.mlx, window_width, window_height, window_title);
	if (!mlx.win.ptr)
		free_mlx(&mlx);
	return (mlx);
}
