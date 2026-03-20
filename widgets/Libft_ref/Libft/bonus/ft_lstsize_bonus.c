/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:32:58 by dzapata           #+#    #+#             */
/*   Updated: 2024/04/12 13:35:47 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft_bonus.h"

int	ft_lstsize(t_list *lst)
{
	int		len;
	t_list	*temp;

	if (!lst)
		return (0);
	len = 1;
	temp = lst->next;
	while (temp)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}
