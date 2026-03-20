/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 22:01:47 by dzapata           #+#    #+#             */
/*   Updated: 2025/04/22 04:37:53 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft_extra.h"

double	ft_atof(char *str, char *dec_sep)
{
	int	err;

	err = 0;
	return (ft_atof2(str, dec_sep, &err));
}

double	get_decimals(char *str)
{
	double	fraction;
	double	scale;

	fraction = 0.0;
	scale = 1.0;
	while (ft_isdigit(*str) && scale != INFINITY)
	{
		fraction = fraction * 10.0 + (*str++ - '0');
		scale *= 10;
	}
	return (fraction / scale);
}

double	ft_atof2(char *str, char *dec_sep, int *err)
{
	double	result;
	double	fraction;
	char	neg;

	while (ft_isspace(*str))
		str++;
	neg = (*str == '-');
	str += (neg || *str == '+');
	result = 0.0;
	while (ft_isdigit(*str) && result != INFINITY)
		result = result * 10.0 + (*str++ - '0');
	if (result == INFINITY)
		return (*err = 1, FLT_MAX);
	fraction = 0.0;
	if (!ft_strncmp(dec_sep, str, ft_strlen(dec_sep)))
		fraction = get_decimals(str + ft_strlen(dec_sep));
	*err = 0;
	if (neg)
		return (-(result + fraction));
	return ((result + fraction));
}
