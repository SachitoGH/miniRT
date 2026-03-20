/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:56:23 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/27 16:32:18 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

int	verify_texture(char *str)
{
	size_t	len;

	len = 0;
	if (!*str)
		return (NO_TEXT_ID_ERR);
	while (str[len] && ft_isalnum(str[len]) && len <= ID_MAX_LEN)
		len++;
	if (str[len] && !ft_isspace(str[len]))
		return (BAD_ID_ERR);
	str = skip_spaces(&str[len]);
	if (!*str)
		return (MISSING_ARGS_ERR);
	while (str && !ft_isspace(*str))
		str++;
	if (*skip_spaces(str))
		return (EXTRA_ARGS_ERR);
	return (0);
}

int	verify_material(char *str)
{
	size_t	len;
	int		err;

	len = 0;
	if (!*str)
		return (NO_MAT_ID_ERR);
	while (str[len] && ft_isalnum(str[len]) && len <= ID_MAX_LEN)
		len++;
	if (str[len] && !ft_isspace(str[len]))
		return (BAD_ID_ERR);
	str = skip_spaces(&str[len]);
	if (!*str)
		return (MISSING_ARGS_ERR);
	err = verify_doubles(&str, 4, MIN_BRIGHTNESS, MAX_BRIGHTNESS);
	if (err)
		return (err);
	str = move_arg(str) + ft_strlen(ARGS_SEP);
	err = verify_doubles(&str, 3, MIN_MAT_VAL, MAX_MAT_VAL);
	if (err)
		return (err);
	str = move_arg(str);
	if (*str && (!ft_isspace(*str) || *skip_spaces(str)))
		return (EXTRA_ARGS_ERR);
	return (0);
}

int	verify_pattern(char *str)
{
	size_t	len;
	int		err;

	len = 0;
	if (!*str)
		return (NO_PAT_ID_ERR);
	while (str[len] && ft_isalnum(str[len]) && len <= ID_MAX_LEN)
		len++;
	if (str[len] && !ft_isspace(str[len]))
		return (BAD_ID_ERR);
	str = skip_spaces(&str[len]);
	err = verify_pattern_type(str);
	if (err)
		return (err);
	str = skip_spaces(move_arg(str));
	err = verify_basics(&str);
	if (err)
		return (err);
	err = verify_color(&str);
	if (err)
		return (err);
	if (*str && (!ft_isspace(*str) || *skip_spaces(str)))
		return (EXTRA_ARGS_ERR);
	return (0);
}

int	verify_camera(char *str)
{
	int	err;

	err = verify_position(&str);
	if (err)
		return (err);
	err = verify_orientation(&str);
	if (err)
		return (err);
	if (!*str)
		return (MISSING_ARGS_ERR);
	err = verify_int(str, ft_strlen(ARGS_SEP), MIN_FOV, MAX_FOV);
	if (err)
		return (err);
	if (*skip_spaces(move_arg(str)))
		return (EXTRA_ARGS_ERR);
	return (0);
}

int	verify_amb_light(char *str)
{
	int	err;

	if (!str)
		return (MISSING_ARGS_ERR);
	err = verify_double(str, ft_strlen(ARGS_SEP),
			MIN_BRIGHTNESS, MAX_BRIGHTNESS);
	if (err)
		return (err);
	str = skip_spaces(move_args(str));
	err = verify_color(&str);
	if (err)
		return (err);
	if (str && *str)
		return (EXTRA_ARGS_ERR);
	return (0);
}
