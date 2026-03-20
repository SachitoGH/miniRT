/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   click_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:19:41 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/03 01:56:26 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

t_image	*get_image(t_minirt *rt, int x, int y)
{
	if (is_within_image(&rt->control, x, y))
		return (&rt->control);
	else if (is_within_image(&rt->general, x, y))
		return (&rt->general);
	return (NULL);
}

bool	is_within_bounds(t_drawable_container *dc, int x, int y)
{
	return (x >= dc->widget.x && (long) x <= dc->widget.x
		+ get_widget_width(&dc->widget) + dc->margin_left + dc->margin_right
		&& y >= dc->widget.y && (long) y <= dc->widget.y
		+ get_widget_height(&dc->widget) + dc->margin_top + dc->margin_bottom);
}

void	has_clicked_button(t_minirt *rt, int x, int y)
{
	int			i;
	t_event		e;

	e.img = get_image(rt, x, y);
	if (!e.img)
		return ;
	i = -1;
	e.rt = rt;
	while (++i < (CONTROL_PARAMS + GENERAL_PARAMS))
	{
		e.param = &rt->spinners[i];
		if (!image_has_widget(e.img, &e.param->spinner.widget))
			continue ;
		if (is_within_bounds(&e.param->spinner.decrease.text_container,
				x - e.img->x, y - e.img->y))
			e.param->spinner.decrease.onclick(&e);
		else if (is_within_bounds(&e.param->spinner.increase.text_container,
				x - e.img->x, y - e.img->y))
			e.param->spinner.increase.onclick(&e);
		else
			continue ;
		break ;
	}
}
