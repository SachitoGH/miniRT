/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:23:01 by dzapata           #+#    #+#             */
/*   Updated: 2024/08/17 20:37:46 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft_extra.h"

int	free_code(void *ptr, int err_code)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
	return (err_code);
}

int	free_table_code(char **table, int err_code)
{
	free_table((void **)table);
	return (err_code);
}
