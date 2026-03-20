/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:44:39 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/28 20:09:43 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

char	*move_arg(char *str)
{
	while (str && *str && (!ft_isspace(*str) && *str != ARGS_SEP[0]))
		str++;
	return (str);
}

char	*move_args(char *str)
{
	while (*str && (!ft_isspace(*str)))
		str++;
	return (str);
}

void	sort_data(t_object_data *hits, int count)
{
	int				i;
	int				j;
	t_object_data	tmp;

	i = 0;
	while (++i < count)
	{
		tmp = hits[i];
		j = i - 1;
		while (j >= 0 && hits[j].t > tmp.t)
		{
			hits[j + 1] = hits[j];
			j--;
		}
		hits[j + 1] = tmp;
	}
}

bool	equal(float a, float b)
{
	return (fabsf(a - b) < F_EPSILON);
}

t_fvector3	euler_to_radiants(t_fvector3 e)
{
	return ((t_fvector3){
		e.x * DEG_RADIANTS,
		e.y * DEG_RADIANTS,
		e.z * DEG_RADIANTS});
}
