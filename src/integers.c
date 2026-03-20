/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:38:48 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/25 17:12:44 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

bool	i_in_bounds(int n, int lower_limit, int upper_limit)
{
	return (n <= upper_limit && n >= lower_limit);
}

int	verify_int(char *str, size_t args_len, int min_val, int max_val)
{
	size_t	i;
	int		err;

	if (!str)
		return (BAD_VALUE_ERR);
	i = (str[0] == '-' || str[0] == '+');
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] && (!ft_isspace(str[i])
			&& ft_strncmp(&str[i], ARGS_SEP, args_len)))
		return (BAD_VALUE_ERR);
	err = 0;
	if (!i_in_bounds(ft_atoi2(&str[0], &err), min_val, max_val) || err)
		return (BAD_VALUE_ERR);
	return (0);
}

int	verify_ints(char **str, unsigned int n_ints, int min_val, int max_val)
{
	unsigned int	n;
	int				err;
	size_t			args_len;

	n = 0;
	args_len = ft_strlen(ARGS_SEP);
	while (++n <= n_ints)
	{
		if (!**str || ft_isspace(**str))
			return (BAD_VALUE_ERR);
		err = verify_int(*str, args_len, min_val, max_val);
		if (err)
			return (err);
		*str = move_arg(*str);
		if (n == n_ints)
			break ;
		if (!**str || ft_isspace(**str))
			return (MISSING_ARGS_ERR);
		*str += args_len;
	}
	return (0);
}
