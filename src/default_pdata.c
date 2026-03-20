/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_pdata.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:08:51 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/19 17:10:34 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

void	init_def_pat_data(t_def_pat_data *data)
{
	data[0] = (t_def_pat_data){STRIP_ID, strip_at, P_STRIPE};
	data[1] = (t_def_pat_data){RING_ID, ring_at, P_RING};
	data[2] = (t_def_pat_data){CHECK_ID, check_at, P_CHECKER};
	data[3] = (t_def_pat_data){GRADIENT_ID, gradient_at, P_GRADIENT};
}

t_def_pat_data	*get_pattern_by_str(char *str, t_def_pat_data *p)
{
	int		i;

	i = -1;
	while (++i < N_PATTERNS)
	{
		if (!ft_strncmp(str, p[i].id, ft_strlen(p[i].id)))
			return (&p[i]);
	}
	return (NULL);
}

t_def_pat_data	*get_pattern_by_type(t_pattern_type type, t_def_pat_data *p)
{
	int		i;

	i = -1;
	while (++i < N_OBJ_FILE)
	{
		if (type == p[i].type)
			return (&p[i]);
	}
	return (NULL);
}
