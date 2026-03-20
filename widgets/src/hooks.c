/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:50:04 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/27 16:54:14 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

int	end(t_minirt *rt)
{
	mlx_hook(rt->mlx.win.ptr, MOUSE_PRESS, MOUSE_PRESS_MASK, NULL, NULL);
	mlx_hook(rt->mlx.win.ptr, MOUSE_RELEASE, MOUSE_RELEASE_MASK, NULL, NULL);
	mlx_hook(rt->mlx.win.ptr, MOUSE_MOTION, MOUSE_MOTION_MASK, NULL, NULL);
	mlx_hook(rt->mlx.win.ptr, DESTROY_NOTIFY, DESTROY_NOTIFY, NULL, NULL);
	mlx_hook(rt->mlx.win.ptr, KEY_PRESS, KEY_PRESS_MASK, NULL, NULL);
	mlx_hook(rt->mlx.win.ptr, KEY_RELEASE, KEY_RELEASE_MASK, NULL, NULL);
	clean_rt_stack(rt);
	exit(EXIT_SUCCESS);
	return (0);
}

void	set_hooks(t_minirt *rt)
{
	mlx_hook(rt->mlx.win.ptr, MOUSE_PRESS, MOUSE_PRESS_MASK, &mouse_press, rt);
	mlx_hook(rt->mlx.win.ptr, MOUSE_RELEASE, MOUSE_RELEASE_MASK,
		&mouse_release, rt);
	mlx_hook(rt->mlx.win.ptr, MOUSE_MOTION, MOUSE_MOTION_MASK,
		&mouse_motion, rt);
	mlx_hook(rt->mlx.win.ptr, DESTROY_NOTIFY, DESTROY_NOTIFY, &end, rt);
	mlx_hook(rt->mlx.win.ptr, KEY_PRESS, KEY_PRESS_MASK, &key_press, rt);
	mlx_hook(rt->mlx.win.ptr, KEY_RELEASE, KEY_RELEASE_MASK, &key_release, rt);
}
