/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:41:27 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/30 15:07:24 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

void	precalculations(t_scene *s, t_render_info *info, int i)
{
	t_fvector4	offset;

	info->p = get_hitted(info, s->depth[i].t);
	info->eye = negate4(info->dir);
	info->p_object = smatrix4_multiply_vec4(&s->depth[i].obj->inverse, info->p);
	info->normal = smatrix4_multiply_vec4(&s->depth[i].obj->transpose,
			s->depth[i].obj->data->normal_at(s->depth[i].obj, info->p_object));
	info->normal.w = 0;
	info->normal = normalize4(info->normal);
	if (dot_product4(info->normal, info->eye) < F_EPSILON)
		info->normal = negate4(info->normal);
	offset = multiplyf4(info->normal, 0.01f);
	info->p_moved = add_vec4(info->p, offset);
	info->reflect = reflect(info->dir, info->normal);
}

int	paint(t_scene *s, t_render_info *info)
{
	int	i;
	int	hitted;

	hitted = hit_objects(s, info);
	sort_data(s->depth, hitted);
	i = 0;
	while (i < hitted && s->depth[i].t < F_EPSILON)
		i++;
	if (i == hitted)
		return (info->bg_color.rgb);
	precalculations(s, info, i);
	return (shade_point(s, info, i));
}

void	render_init(t_scene *s, t_render_info *i)
{
	i->origin = s->camera.origin;
	i->ambient = multiplyf(s->camera.alight_color.normalized,
			s->camera.alight_brightness);
	i->bg_color.normalized = normalize(multiply_vec(i->ambient,
				s->background.normalized));
	i->bg_color.rgb = normalized_to_rgb(i->bg_color.normalized);
}

t_fvector4	ray_for_pixel(t_camera *c, int px, int py)
{
	float		world_x;
	float		world_y;
	t_fvector4	pixel;
	t_fvector4	dir;

	world_x = c->viewport.half_width - ((px + 0.5f) * c->viewport.pixel_size);
	world_y = c->viewport.half_height - ((py + 0.5f) * c->viewport.pixel_size);
	pixel = smatrix4_multiply_vec4(&c->inverse, point(world_x, world_y, -1.0f));
	dir = normalize4(substract_vec4(pixel, c->origin));
	return (dir);
}

void	render(t_scene *s, t_image *img)
{
	t_render_info	info;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	render_init(s, &info);
	while (i < img->height)
	{
		j = 0;
		while (j < img->width)
		{
			info.depth = 4;
			info.dir = ray_for_pixel(&s->camera, j, i);
			*(unsigned int *)(img->addr + (i * img->line_length + j
						* (img->bits_per_pixel / 8))) = paint(s, &info);
			j++;
		}
		i++;
	}
}

void    low_render(t_scene *s, t_image *img)
{
    t_render_info   info;
    unsigned int    i; // Current row index (y-coordinate)
    unsigned int    j; // Current column index (x-coordinate)
    unsigned int    dx; // Offset for filling pixels in x-direction
    unsigned int    dy; // Offset for filling pixels in y-direction
    unsigned int    pixel_color; // Stores the computed color for a block of pixels

    render_init(s, &info);

    for (i = 0; i < img->height; i += QUALITY)
    {
        for (j = 0; j < img->width; j += QUALITY)
        {

            info.depth = 4;

            info.dir = ray_for_pixel(&s->camera, j, i);
            pixel_color = paint(s, &info);

            for (dy = 0; dy < QUALITY && (i + dy) < img->height; dy++)
            {
                for (dx = 0; dx < QUALITY && (j + dx) < img->width; dx++)
                {
                    *(unsigned int *)(img->addr + ((i + dy) * img->line_length + (j + dx)
                                        * (img->bits_per_pixel / 8))) = pixel_color;
                }
            }
        }
	}
}