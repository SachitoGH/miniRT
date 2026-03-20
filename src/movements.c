/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 21:45:24 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/30 04:53:33 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

void	move_forward(t_minirt *rt, float steps)
{
	t_fvector3	f;

	f.x = -rt->scene.camera.transform.data[2][0];
	f.y = -rt->scene.camera.transform.data[2][1];
	f.z = -rt->scene.camera.transform.data[2][2];
	f = add_vec(rt->scene.camera.position, multiplyf(f, steps));
	if (!d_in_bounds(f.x, MIN_VALUES, MAX_VALUES)
		|| !d_in_bounds(f.y, MIN_VALUES, MAX_VALUES)
		|| !d_in_bounds(f.z, MIN_VALUES, MAX_VALUES))
		return ;
	rt->scene.camera.position = f;
	camera_transform(&rt->scene.camera);
	calculate_objects_camera(&rt->scene);
	low_render(&rt->scene, &rt->render);
	mlx_put_image_to_window(rt->mlx.mlx, rt->mlx.win.ptr,
		rt->render.ptr, rt->render.x, rt->render.y);
}

void	move_right(t_minirt *rt, float steps)
{
	t_fvector3	r;

	r.x = rt->scene.camera.transform.data[0][0];
	r.y = rt->scene.camera.transform.data[0][1];
	r.z = rt->scene.camera.transform.data[0][2];
	r = add_vec(rt->scene.camera.position, multiplyf(r, steps));
	if (!d_in_bounds(r.x, MIN_VALUES, MAX_VALUES)
		|| !d_in_bounds(r.y, MIN_VALUES, MAX_VALUES)
		|| !d_in_bounds(r.z, MIN_VALUES, MAX_VALUES))
		return ;
	rt->scene.camera.position = r;
	camera_transform(&rt->scene.camera);
	calculate_objects_camera(&rt->scene);
	low_render(&rt->scene, &rt->render);
	mlx_put_image_to_window(rt->mlx.mlx, rt->mlx.win.ptr,
		rt->render.ptr, rt->render.x, rt->render.y);
}

void	move_up(t_minirt *rt, float steps)
{
	t_fvector3	u;

	u.x = rt->scene.camera.transform.data[1][0];
	u.y = rt->scene.camera.transform.data[1][1];
	u.z = rt->scene.camera.transform.data[1][2];
	u = add_vec(rt->scene.camera.position, multiplyf(u, steps));
	if (!d_in_bounds(u.x, MIN_VALUES, MAX_VALUES)
		|| !d_in_bounds(u.y, MIN_VALUES, MAX_VALUES)
		|| !d_in_bounds(u.z, MIN_VALUES, MAX_VALUES))
		return ;
	rt->scene.camera.position = u;
	camera_transform(&rt->scene.camera);
	calculate_objects_camera(&rt->scene);
	low_render(&rt->scene, &rt->render);
	mlx_put_image_to_window(rt->mlx.mlx, rt->mlx.win.ptr,
		rt->render.ptr, rt->render.x, rt->render.y);
}

void	rotate_up(t_minirt *rt, float steps)
{
	t_smatrix4	rotation;

	rotation = smatrix4_rotate_x(steps * DEG_RADIANTS);
	rt->scene.camera.rotation = smatrix4_multiply(&rt->scene.camera.rotation,
			&rotation);
	camera_transform(&rt->scene.camera);
	calculate_objects_camera(&rt->scene);
	low_render(&rt->scene, &rt->render);
	mlx_put_image_to_window(rt->mlx.mlx, rt->mlx.win.ptr,
		rt->render.ptr, rt->render.x, rt->render.y);
}

void	rotate_sides(t_minirt *rt, float steps)
{
	t_smatrix4	rotation;

	rotation = smatrix4_rotate_y(steps * DEG_RADIANTS);
	rt->scene.camera.rotation = smatrix4_multiply(&rt->scene.camera.rotation,
			&rotation);
	camera_transform(&rt->scene.camera);
	calculate_objects_camera(&rt->scene);
	low_render(&rt->scene, &rt->render);
	mlx_put_image_to_window(rt->mlx.mlx, rt->mlx.win.ptr,
		rt->render.ptr, rt->render.x, rt->render.y);
}
