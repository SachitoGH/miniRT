/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 02:00:15 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/30 04:55:22 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

int	create_images(int w_width, int w_height, t_minirt *rt)
{
	rt->render = new_image(rt->mlx.mlx,
			(t_ivector2){(int) round(w_width * RENDER_PERCENT), w_height},
			rt->render.bg_color, 0);
	if (!rt->render.ptr)
		return (MLX_IMG_ERR);
	rt->control = new_image(rt->mlx.mlx,
			(t_ivector2){(int) round(w_width * CONTROL_PERCENT), w_height},
			rt->control.bg_color, CONTROL_PARAMS);
	if (!rt->control.ptr)
		return (MLX_IMG_ERR);
	rt->general = new_image(rt->mlx.mlx,
			(t_ivector2){(int) round(w_width * GENERAL_PERCENT), w_height},
			rt->general.bg_color, GENERAL_PARAMS);
	if (!rt->general.ptr)
		return (MLX_IMG_ERR);
	rt->control.x = 0;
	rt->control.y = 0;
	rt->render.x = rt->control.width + 1;
	rt->render.y = 0;
	rt->general.x = rt->render.x + rt->render.width + 1;
	rt->general.y = 0;
	return (0);
}

int	init_minirt(t_text *t, t_ivector2 w_size, t_minirt *rt,
	t_def_obj_data *data)
{
	int	err;

	rt->mlx = create_mlx(w_size.x, w_size.y, WINDOW_TITLE);
	if (!rt->mlx.win.ptr)
		return (MLX_ERR);
	err = parse_rt_file(&rt->mlx, &rt->scene, t, data);
	if (err)
		return (err);
	err = create_images(w_size.x, w_size.y, rt);
	if (err)
		return (err);
	rt->spinners = malloc(sizeof(t_number_spinner)
			* (CONTROL_PARAMS + GENERAL_PARAMS));
	if (!rt->spinners)
		return (MALLOC_ERR);
	init_params(rt->spinners, (CONTROL_PARAMS + GENERAL_PARAMS));
	return (0);
}

bool	verify_macros(void)
{
	if ((RENDER_PERCENT + CONTROL_PERCENT + GENERAL_PERCENT) != 1.0f)
		print_err(BAD_PANEL_SIZE_ERR);
	if (!ft_strncmp(ARGS_SEP, DEC_SEP, ft_strlen(ARGS_SEP)))
		return (print_err(ARGS_DECIMAL_ERR), false);
	return (true);
}

bool	init(int fd, t_minirt *rt, int w_width, int w_height)
{
	t_text	*t;
	int		err;

	if (!verify_macros())
		return (close(fd), false);
	set_rt_null(rt);
	t = get_file(fd, true);
	if (!t)
		return (print_err(MALLOC_ERR), false);
	init_def_data_obj(rt->o_data);
	init_def_pat_data(rt->p_data);
	err = verify_content(t, &rt->scene, rt->o_data);
	if (err)
		return (print_err(err), clean_file(t, fd), false);
	err = init_minirt(t, (t_ivector2){w_width, w_height}, rt, rt->o_data);
	if (err)
		return (print_err(err), clean_file(t, fd),
			clean_rt_stack(rt), false);
	calculate_camera(&rt->scene.camera, &rt->render);
	calculus(&rt->scene);
	clean_file(t, fd);
	link_spinners(rt);
	link_control_values(rt);
	return (true);
}

int	minirt(int fd, int w_width, int w_height)
{
	t_minirt	rt;
	int			i;

	rt = (t_minirt){0};
	if (!init(fd, &rt, w_width, w_height))
		return (EXIT_FAILURE);
	set_background(&rt.control, rt.control.bg_color);
	set_background(&rt.general, rt.general.bg_color);
	place_control(&rt);
	i = -1;
	while (++i < rt.scene.amount_patterns)
		rt.scene.patterns[i].data = get_pattern_by_type(
				rt.scene.patterns[i].type, rt.p_data);
	render(&rt.scene, &rt.render);
	set_hooks(&rt);
	draw_image_window(&rt.mlx, &rt.control);
	draw_control_strings(&rt, &rt.control);
	mlx_put_image_to_window(rt.mlx.mlx, rt.mlx.win.ptr, rt.general.ptr,
		rt.general.x, rt.general.y);
	mlx_put_image_to_window(rt.mlx.mlx, rt.mlx.win.ptr, rt.render.ptr,
		rt.render.x, rt.render.y);
	mlx_do_key_autorepeaton(rt.mlx.mlx);
	mlx_loop(rt.mlx.mlx);
	clean_rt_stack(&rt);
	return (EXIT_SUCCESS);
}
