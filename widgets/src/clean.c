/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 04:32:13 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/26 19:23:03 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

void	destroy_textures(t_mlx *mlx, t_scene *s)
{
	int	i;

	if (s->textures)
	{
		i = -1;
		while (++i < s->amount_textures)
		{
			if (s->textures[i].img)
				mlx_destroy_image(mlx->mlx, s->textures[i].img);
		}
		free(s->textures);
		s->textures = NULL;
	}
}

void	clean_rt_stack(t_minirt *rt)
{
	if (rt)
	{
		destroy_image(rt->mlx.mlx, &rt->render);
		destroy_image(rt->mlx.mlx, &rt->control);
		destroy_image(rt->mlx.mlx, &rt->general);
		destroy_textures(&rt->mlx, &rt->scene);
		free(rt->scene.objects);
		free(rt->scene.depth);
		free(rt->scene.lights);
		free(rt->scene.patterns);
		free(rt->scene.materials);
		free_mlx(&rt->mlx);
		free(rt->spinners);
	}
}
