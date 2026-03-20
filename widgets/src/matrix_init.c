/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:21:07 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/27 16:21:36 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/dimensions.h"

t_smatrix4	smatrix4_identity(void)
{
	t_smatrix4	m;

	m = (t_smatrix4){0};
	m.data[0][0] = 1;
	m.data[1][1] = 1;
	m.data[2][2] = 1;
	m.data[3][3] = 1;
	return (m);
}

t_smatrix4	smatrix4_zero(void)
{
	return ((t_smatrix4){0});
}
