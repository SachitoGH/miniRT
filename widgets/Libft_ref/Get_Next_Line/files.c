/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 04:02:22 by dzapata           #+#    #+#             */
/*   Updated: 2025/04/09 21:09:56 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clean_file(t_text *text, int fd)
{
	int	err_temp;
	int	err;

	if (text)
	{
		err_temp = errno;
		close(fd);
		get_next_line3(fd, &err);
		errno = err_temp;
		ft_lstclear(&text->data, &free_ptr);
		free(text);
	}
}

static void	remove_dummy(t_text *text)
{
	t_list	*dummy;

	dummy = text->data;
	text->data = dummy->next;
	free(dummy);
}

static t_text	*init_file(void)
{
	t_text	*t;

	t = malloc(sizeof(t_text));
	if (!t)
		return (NULL);
	t->data = ft_lstnew(NULL);
	if (!t->data)
		return (free(t), NULL);
	t->lines = 0;
	return (t);
}

t_text	*get_file(int fd, bool ignore_empty_lines)
{
	char	*line;
	t_text	*text;
	t_list	*last;
	int		err;

	text = init_file();
	if (!text)
		return (NULL);
	last = text->data;
	line = get_next_line3(fd, &err);
	while (line)
	{
		if (!(ignore_empty_lines && !skip_spaces(line)[0]))
		{
			if (ft_lstadd(&last, line) == -1)
				return (free(line), clean_file(text, fd), NULL);
			text->lines++;
		}
		else
			free(line);
		line = get_next_line3(fd, &err);
	}
	if (err)
		return (clean_file(text, fd), NULL);
	return (remove_dummy(text), text);
}
