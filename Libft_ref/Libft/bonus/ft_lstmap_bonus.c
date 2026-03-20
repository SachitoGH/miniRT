/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:58:47 by dzapata           #+#    #+#             */
/*   Updated: 2024/04/12 13:33:56 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft_bonus.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*begin;
	t_list	*temp;

	if (!lst || !f || !del)
		return (NULL);
	new_list = ft_lstnew(f(lst->content));
	if (!new_list)
		return (NULL);
	begin = new_list;
	temp = lst->next;
	while (temp)
	{
		new_list->next = ft_lstnew(f(temp->content));
		if (!(new_list->next))
		{
			ft_lstclear(&begin, del);
			return (NULL);
		}
		temp = temp->next;
		new_list = new_list->next;
	}
	return (begin);
}
