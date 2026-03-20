/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preloaded.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:17:52 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/21 03:37:30 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

bool	is_texture(char *str, t_texture *t, int n_textures)
{
	int	i;

	i = -1;
	while (++i < n_textures && t[i].img)
		if (!ft_strncmp(str, t[i].id, ID_MAX_LEN + 1))
			return (true);
	return (false);
}

bool	is_material(char *str, t_material *m, int n_materials)
{
	int	i;

	i = -1;
	while (++i < n_materials)
		if (!ft_strncmp(str, m[i].id, ID_MAX_LEN + 1))
			return (true);
	return (false);
}

bool	is_pattern(char *str, t_pattern *p, int n_pattern)
{
	int	i;

	i = -1;
	while (++i < n_pattern)
		if (!ft_strncmp(str, p[i].id, ID_MAX_LEN + 1))
			return (true);
	return (false);
}

bool	is_unique_id(char *str, t_scene *s)
{
	int	i;

	i = -1;
	while (++i < s->amount_textures)
		if (!ft_strncmp(str, s->textures[i].id, ID_MAX_LEN + 1))
			return (false);
	i = -1;
	while (++i < s->amount_materials)
		if (!ft_strncmp(str, s->materials[i].id, ID_MAX_LEN + 1))
			return (false);
	i = -1;
	while (++i < s->amount_patterns)
		if (!ft_strncmp(str, s->patterns[i].id, ID_MAX_LEN + 1))
			return (false);
	return (true);
}
