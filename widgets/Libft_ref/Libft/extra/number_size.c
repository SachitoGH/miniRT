/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 03:27:54 by dzapata           #+#    #+#             */
/*   Updated: 2025/03/30 04:38:06 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft_extra.h"

int	get_int_size(int n)
{
	int		size;

	if (n == 0)
		return (1);
	size = (n < 0);
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

int	get_uint_size(unsigned int n)
{
	int		size;

	if (n == 0)
		return (1);
	size = 0;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

int	get_float_size(float num)
{
	int		size;
	int		temp;
	float	decimal;

	temp = get_int_size((int) num);
	size = temp;
	decimal = num - ((int) num);
	if (decimal != 0.0f)
	{
		size++;
		while (decimal != 0.0f)
		{
			decimal *= 10;
			temp = (int) decimal;
			decimal -= temp;
			size++;
		}
	}
	return (size);
}

int	get_double_size(double num)
{
	int		size;
	int		temp;
	double	decimal;

	temp = get_int_size((int) num);
	size = temp;
	decimal = num - ((int) num);
	if (decimal != 0.0f)
	{
		size++;
		while (decimal != 0.0f)
		{
			decimal *= 10;
			temp = (int) decimal;
			decimal -= temp;
			size++;
		}
	}
	return (size);
}
