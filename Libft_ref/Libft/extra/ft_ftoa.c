/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 03:06:23 by dzapata           #+#    #+#             */
/*   Updated: 2025/04/21 22:08:25 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft_extra.h"

static void	decimal(char **str, float num, int n_dec, int *len)
{
	int		ilen;
	int		inum;
	float	decimal;
	int		dec;

	if (n_dec == 0)
		return ;
	decimal = num - (int) num;
	ilen = get_int_size((int) num) + (num > -1.0f && num < 0.0f);
	(*str)[ilen] = '.';
	*len = ilen++;
	dec = -1;
	if (decimal < 0.0f)
		decimal = -decimal;
	while ((++dec < n_dec && n_dec > -1)
		|| (decimal > FLT_EPSILON && n_dec < 0))
	{
		decimal *= 10.0;
		inum = (int) decimal;
		decimal -= inum;
		(*str)[ilen++] = inum + '0';
	}
}

char	*ft_ftoa(float num)
{
	char	*str;
	int		len;
	int		temp;

	len = get_float_size(num);
	if (num < 0.0f)
	{
		len++;
		num = -num;
	}
	str = malloc (len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	temp = (int) num;
	if (num - temp > 0.0f)
		decimal(&str, num, temp, &len);
	while ((--len) >= 0 && temp >= 0)
	{
		str[len] = ((temp % 10) + '0');
		temp /= 10;
	}
	if (str[0] == '0' && ((int) num) != 0)
		str[0] = '-';
	return (str);
}

void	ft_ftoa2(float num, char *str)
{
	int		len;
	int		temp;
	char	is_negative;

	num += FLT_EPSILON;
	is_negative = num < 0.0f;
	len = get_float_size(num);
	str[len] = '\0';
	temp = (int) num;
	if (is_negative)
		temp = -temp;
	if (num - temp > 0.0f)
		decimal(&str, num, temp, &len);
	while ((--len) >= 0 && temp >= 0)
	{
		str[len] = ((temp % 10) + '0');
		temp /= 10;
	}
	if (is_negative)
		str[0] = '-';
}

void	ft_ftoa3(float num, char *str, int decimals)
{
	int		len;
	int		temp;
	char	is_negative;

	num += FLT_EPSILON;
	is_negative = num < 0.0f;
	temp = (int) num;
	len = get_int_size(temp) + (!temp && is_negative);
	if (decimals > 0)
		len += decimals + 1;
	str[len] = '\0';
	if (decimals > 0)
		decimal(&str, num, decimals, &len);
	if (temp < 0)
		temp = -temp;
	while ((--len) >= 0 && temp >= 0)
	{
		str[len] = ((temp % 10) + '0');
		temp /= 10;
	}
	if (is_negative)
		str[0] = '-';
}
