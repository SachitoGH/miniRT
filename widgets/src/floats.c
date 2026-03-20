/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:15:59 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/27 17:27:29 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

bool	d_in_bounds(double n, double lower_limit, double upper_limit)
{
	return (n <= upper_limit && n >= lower_limit);
}

static int	no_decimal_sep(char *s, double min, double max)
{
	int	err;

	if ((!d_in_bounds(ft_atof2(s, DEC_SEP, &err), min, max) || err))
		return (BAD_VALUE_ERR);
	return (0);
}

int	verify_double(char *s, size_t args_len, double min, double max)
{
	int		err;
	size_t	i;
	size_t	dec_len;

	i = (s[0] == '+' || s[0] == '-');
	dec_len = i;
	while (s[i] && s[i] != DEC_SEP[0] && s[i] != ARGS_SEP[0]
		&& !ft_isspace(s[i]))
		if (!ft_isdigit(s[i++]))
			return (BAD_VALUE_ERR);
	if (dec_len == i)
		return (BAD_VALUE_ERR);
	dec_len = ft_strlen(DEC_SEP);
	if ((!s[i] || ft_strncmp(&s[i], DEC_SEP, dec_len)))
		return (no_decimal_sep(s, min, max));
	i += dec_len;
	dec_len = i;
	while (s[i] && s[i] != ARGS_SEP[0] && !ft_isspace(s[i]))
		if (!ft_isdigit(s[i++]))
			return (BAD_VALUE_ERR);
	if (dec_len == i || (s[i] && !ft_isspace(s[i]) && ft_strncmp(&s[i],
				ARGS_SEP, args_len)) || (!d_in_bounds(ft_atof2(s, DEC_SEP,
					&err), min, max) || err))
		return (BAD_VALUE_ERR);
	return (0);
}

int	verify_doubles(char **str, unsigned int n_floats,
	double min_val, double max_val)
{
	unsigned int	n;
	int				err;
	size_t			args_len;

	n = 0;
	args_len = ft_strlen(ARGS_SEP);
	while (++n <= n_floats)
	{
		if (!**str || ft_isspace(**str))
			return (MISSING_ARGS_ERR);
		err = verify_double(*str, args_len, min_val, max_val);
		if (err)
			return (err);
		if (n != n_floats)
		{
			*str = move_arg(*str);
			if (str && *str)
				*str += args_len;
		}
	}
	return (0);
}
