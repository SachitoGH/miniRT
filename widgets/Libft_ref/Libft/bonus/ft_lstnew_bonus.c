/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:37:26 by dzapata           #+#    #+#             */
/*   Updated: 2024/04/12 15:54:48 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft_bonus.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*member;

	member = (t_list *) malloc(sizeof(t_list));
	if (!member)
		return (NULL);
	if (!content)
		member->content = NULL;
	else
		member->content = content;
	member->next = NULL;
	return (member);
}
