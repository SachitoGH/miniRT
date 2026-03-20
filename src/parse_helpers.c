/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:58:39 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/19 18:33:59 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

// Parse a string who represents 3 or less arguments of type float.
void	parse_ftriad(t_fvector3 *triad, char *str)
{
	int		i;
	size_t	sep_len;

	i = -1;
	sep_len = ft_strlen(ARGS_SEP);
	while (++i < 3 && str)
	{
		if (i == 0)
			triad->x = ft_atof(str, DEC_SEP);
		else if (i == 1)
			triad->y = ft_atof(str, DEC_SEP);
		else
			triad->z = ft_atof(str, DEC_SEP);
		str = move_arg(str);
		if (!str || str[0] != ARGS_SEP[0])
			break ;
		str += sep_len;
	}
	if (i < 1)
		triad->y = triad->x;
	if (i < 2)
		triad->z = triad->y;
}

// Parse a string who represents a color. the values are expected to be amonst
// the valid limit defined in the header
void	parse_color(int *color, char *s)
{
	char	*sep;
	size_t	sep_len;

	sep_len = ft_strlen(ARGS_SEP);
	sep = ft_strchr(s, ARGS_SEP[0]);
	sep[0] = '\0';
	*color = ft_atoi(s) << 16;
	sep[0] = ARGS_SEP[0];
	s = sep + sep_len;
	sep = ft_strchr(s, ARGS_SEP[0]);
	sep[0] = '\0';
	*color |= ft_atoi(s) << 8;
	sep[0] = ARGS_SEP[0];
	s = sep + sep_len;
	*color |= ft_atoi(s);
}

bool	verify_unique_id(char *str, t_scene *s, size_t *len)
{
	char	*temp;
	char	temp2;
	bool	is_unique;

	temp = move_args(str);
	temp2 = *temp;
	temp[0] = '\0';
	is_unique = is_unique_id(str, s);
	temp[0] = temp2;
	if (len)
		*len = temp - str;
	return (is_unique);
}
