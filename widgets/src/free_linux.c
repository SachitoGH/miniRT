/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_linux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:33:03 by dzapata           #+#    #+#             */
/*   Updated: 2025/03/10 15:36:46 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/widgets.h"

void	free_mlx(t_mlx *mlx)
{
	if (mlx)
	{
		if (mlx->win.ptr)
		{
			mlx_destroy_window(mlx->mlx, mlx->win.ptr);
			mlx->win.ptr = NULL;
		}
		if (mlx->mlx)
		{
			mlx_destroy_display(mlx->mlx);
			free(mlx->mlx);
			mlx->mlx = NULL;
		}
	}
}
