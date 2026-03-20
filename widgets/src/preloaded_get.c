/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preloaded_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 03:37:04 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/21 03:37:37 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

t_texture	*get_texture(char *str, t_texture *textures, int n_textures)
{
	int		i;

	i = -1;
	while (++i < n_textures)
	{
		if (!ft_strncmp(str, textures[i].id, ID_MAX_LEN + 1))
			return (&textures[i]);
	}
	return (NULL);
}

t_material	*get_material(char *str, t_material *m, int n_materials)
{
	int		i;

	i = -1;
	while (++i < n_materials)
	{
		if (!ft_strncmp(str, m[i].id, ID_MAX_LEN + 1))
			return (&m[i]);
	}
	return (NULL);
}

t_pattern	*get_pattern(char *str, t_pattern *p, int n_pattern)
{
	int		i;

	i = -1;
	while (++i < n_pattern)
	{
		if (!ft_strncmp(str, p[i].id, ID_MAX_LEN + 1))
			return (&p[i]);
	}
	return (NULL);
}

bool	new_texture(t_mlx *mlx, t_texture *t, char *path)
{
	char	*temp;
	char	temp2;

	temp = move_args(path);
	temp2 = *temp;
	temp[0] = '\0';
	t->img = mlx_xpm_file_to_image(mlx->mlx, path, &t->width, &t->height);
	temp[0] = temp2;
	return (t->img != NULL);
}
