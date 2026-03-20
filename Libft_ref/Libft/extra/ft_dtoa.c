/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 03:06:23 by dzapata           #+#    #+#             */
/*   Updated: 2025/04/21 22:08:53 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft_extra.h"

static void	decimal(char **str, double num, int n_dec, int *len)
{
	int		ilen;
	int		inum;
	double	decimal;
	int		dec;

	decimal = num - (int) num;
	ilen = get_int_size((int) num);
	if (n_dec == 0)
		return ;
	(*str)[ilen] = '.';
	*len = ilen;
	ilen++;
	dec = -1;
	while ((++dec < n_dec && n_dec > -1) || (decimal != 0.0f && n_dec < 0))
	{
		decimal *= 10.0;
		inum = (int) decimal;
		decimal -= inum;
		(*str)[ilen] = inum + '0';
		ilen++;
	}
}

char	*ft_dtoa(double num)
{
	char	*str;
	int		len;
	int		temp;

	len = get_double_size(num);
	if (num < 0)
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
		decimal(&str, num, -1, &len);
	while ((--len) >= 0 && temp >= 0)
	{
		str[len] = ((temp % 10) + '0');
		temp /= 10;
	}
	if (str[0] == '0' && ((int) num) != 0)
		str[0] = '-';
	return (str);
}

void	ft_dtoa2(double num, char *str)
{
	int		len;
	int		temp;

	num += DBL_EPSILON;
	len = 0;
	if (num < 0)
	{
		len++;
		num = -num;
	}
	len += get_double_size(num);
	str[len] = '\0';
	temp = (int) num;
	if (num - temp > 0.0f)
		decimal(&str, num, -1, &len);
	while ((--len) >= 0 && temp >= 0)
	{
		str[len] = ((temp % 10) + '0');
		temp /= 10;
	}
	if (str[0] == '0' && ((int) num) != 0)
		str[0] = '-';
}

void	ft_dtoa3(double num, char *str, int decimals)
{
	int		len;
	int		temp;

	num += DBL_EPSILON;
	len = 0;
	if (num < 0)
	{
		len++;
		num = -num;
	}
	temp = (int) num;
	len += get_int_size(temp);
	if (decimals > 0)
		len += decimals + 1;
	str[len] = '\0';
	if (decimals > 0)
		decimal(&str, num, decimals, &len);
	while ((--len) >= 0 && temp >= 0)
	{
		str[len] = ((temp % 10) + '0');
		temp /= 10;
	}
	if (str[0] == '0' && ((int) num) != 0)
		str[0] = '-';
}
