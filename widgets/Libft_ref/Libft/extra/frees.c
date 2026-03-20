/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 02:50:29 by dzapata           #+#    #+#             */
/*   Updated: 2024/06/29 18:29:41 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft_extra.h"

void	*free_null(char **ptr)
{
	free(*ptr);
	(*ptr) = NULL;
	return (NULL);
}

void	free_ptr(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

void	free_table(void **table)
{
	int	i;

	if (!table)
		return ;
	i = -1;
	while (table[++i])
		free_ptr(table[i]);
	free_ptr(table);
}
