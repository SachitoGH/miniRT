/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:41:04 by dzapata           #+#    #+#             */
/*   Updated: 2025/04/07 19:30:56 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../Libft/headers/libft_extra.h"
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef FILES_LIMIT
#  define FILES_LIMIT 128
# endif

# if BUFFER_SIZE > 1048576
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 1048576
# endif

# define BAD_FD_ERR 1
# define READ_ERR	2
# define BUFFER_ERR	3
# define SYSTEM_ERR	4

typedef struct s_text
{
	int		lines;
	t_list	*data;
}	t_text;

void	clean_file(t_text *text, int fd);
t_text	*get_file(int fd, bool ignore_empty_lines);
char	*get_next_line(int fd);
char	*get_next_line2(int fd);
char	*get_next_line3(int fd, int *err) __attribute__((nonnull(2)));

#endif