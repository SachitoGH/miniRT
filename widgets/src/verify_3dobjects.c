/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_3dobjects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:43:41 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/28 17:57:49 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

static int	special(char **str)
{
	int	err;

	err = verify_doubles(str, 2, MIN_VALUES, MAX_VALUES);
	if (err)
		return (err);
	*str = move_arg(*str);
	if (**str != ARGS_SEP[0])
		return (MISSING_ARGS_ERR);
	*str += ft_strlen(ARGS_SEP);
	err = verify_int(*str, ft_strlen(ARGS_SEP), false, true);
	if (err)
		return (err);
	*str = move_arg(*str);
	if (**str && !ft_isspace(**str))
		return (EXTRA_ARGS_ERR);
	*str = skip_spaces(*str);
	return (0);
}

int	verify_plane(char *str)
{
	int	err;

	if (!str)
		return (MISSING_ARGS_ERR);
	err = verify_position(&str);
	if (err)
		return (err);
	err = verify_values(&str, 3, 0, true);
	if (err)
		return (err);
	err = verify_color(&str);
	if (err)
		return (err);
	err = -1;
	while (++err < 3)
		str = skip_spaces(move_arg(str));
	if (*str)
		return (EXTRA_ARGS_ERR);
	return (0);
}

int	verify_special(char *str)
{
	int	err;

	if (!str)
		return (MISSING_ARGS_ERR);
	err = verify_position(&str);
	if (err)
		return (err);
	err = verify_values(&str, 3, 0, true);
	if (err)
		return (err);
	err = verify_values(&str, 3, 2, true);
	if (err)
		return (err);
	err = special(&str);
	if (err)
		return (err);
	err = verify_color(&str);
	if (err)
		return (err);
	err = -1;
	while (++err < 3)
		str = skip_spaces(move_arg(str));
	if (*str)
		return (EXTRA_ARGS_ERR);
	return (0);
}

int	verify_object(char *str)
{
	int	err;

	if (!str)
		return (MISSING_ARGS_ERR);
	err = verify_basics(&str);
	if (err)
		return (err);
	err = -1;
	while (++err < 3)
		str = skip_spaces(move_arg(str));
	if (*str)
		return (EXTRA_ARGS_ERR);
	return (0);
}

int	verify_light(char *str)
{
	int	err;

	err = verify_position(&str);
	if (err)
		return (err);
	if (!*str)
		return (MISSING_ARGS_ERR);
	err = verify_double(str, ft_strlen(ARGS_SEP),
			MIN_BRIGHTNESS, MAX_BRIGHTNESS);
	if (err)
		return (err);
	str = skip_spaces(move_arg(str));
	err = verify_color(&str);
	if (err)
		return (err);
	if (*str)
		return (EXTRA_ARGS_ERR);
	return (0);
}
