/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:25:46 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/25 19:43:53 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

int	verify_position(char **str)
{
	int	err;

	if (!*str)
		return (MISSING_ARGS_ERR);
	err = verify_doubles(str, 3, MIN_VALUES, MAX_VALUES);
	if (err)
		return (err);
	*str = move_arg(*str);
	if (**str && !ft_isspace(**str))
		return (EXTRA_ARGS_ERR);
	*str = skip_spaces(*str);
	return (0);
}

int	verify_orientation(char **str)
{
	int	err;

	if (!*str)
		return (MISSING_ARGS_ERR);
	err = verify_doubles(str, 3, MIN_ORIENTATION, MAX_ORIENTATION);
	if (err)
		return (err);
	*str = move_arg(*str);
	if (**str && !ft_isspace(**str))
		return (EXTRA_ARGS_ERR);
	*str = skip_spaces(*str);
	return (0);
}

int	verify_color(char **str)
{
	int	err;

	if (!*str || !**str)
		return (MISSING_ARGS_ERR);
	err = verify_ints(str, 3, MIN_COLOR, MAX_COLOR);
	if (err)
		return (err);
	if (**str && !ft_isspace(**str))
		return (EXTRA_ARGS_ERR);
	*str = skip_spaces(*str);
	return (0);
}

int	verify_pattern_type(char *str)
{
	t_def_pat_data	patterns[N_PATTERNS];
	int				i;
	char			*temp;

	if (!*str)
		return (MISSING_ARGS_ERR);
	init_def_pat_data(patterns);
	i = -1;
	temp = move_arg(str);
	while (++i < N_PATTERNS)
		if (!ft_strncmp(str, patterns[i].id, temp - str))
			return (0);
	return (INVALID_PAT_ERR);
}

int	verify_values(char **str, unsigned int n_args, unsigned int optional,
	bool end)
{
	int		err;
	size_t	args_len;

	args_len = ft_strlen(ARGS_SEP);
	while (n_args > 0)
	{
		if (!**str && optional < n_args)
			return (MISSING_ARGS_ERR);
		n_args--;
		err = verify_double(*str, args_len, MIN_VALUES, MAX_VALUES);
		if (err)
			return (err);
		*str = move_arg(*str);
		if (!**str || ft_isspace(**str))
			break ;
		*str += args_len;
	}
	if (optional < n_args)
		return (MISSING_ARGS_ERR);
	if ((end && **str && !ft_isspace(**str))
		|| *(*str - args_len) == ARGS_SEP[0])
		return (EXTRA_ARGS_ERR);
	*str = skip_spaces(move_arg(*str));
	return (0);
}
