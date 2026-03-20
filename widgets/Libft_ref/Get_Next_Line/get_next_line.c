/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:41:06 by dzapata           #+#    #+#             */
/*   Updated: 2025/04/07 19:08:56 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(long nl, char **data, int *err)
{
	char	*line;
	char	*temp;

	if (!*data)
		return (*err = SYSTEM_ERR, NULL);
	line = ft_substr(*data, 0, nl + 1);
	if (!line)
		return (*err = SYSTEM_ERR, NULL);
	temp = ft_substr(*data, nl + 1, BUFFER_SIZE);
	free_null(data);
	if (!temp)
		return (*err = SYSTEM_ERR, free_null(&line), *data = NULL);
	*data = temp;
	return (*err = 0, line);
}

char	*get_data(int fd, char **data, int *err)
{
	ssize_t	c_read;
	char	*temp;
	char	line[BUFFER_SIZE + 1];

	line[0] = '\0';
	temp = ft_strchr(*data, '\n');
	while (!temp)
	{
		c_read = read(fd, line, BUFFER_SIZE);
		if (c_read == -1)
			return (*err = SYSTEM_ERR, NULL);
		else if ((!line[0] && !(*data)[0]))
			return (*err = 0, NULL);
		line[c_read] = '\0';
		*data = free_strjoin1(*data, line);
		if (!*data)
			return (*err = SYSTEM_ERR, NULL);
		temp = ft_strchr(*data, '\n');
		if (c_read < BUFFER_SIZE && !temp)
			return (*err = 0, temp = *data, *data = NULL, temp);
	}
	return (get_line(temp - *data, data, err));
}

char	*get_next_line(int fd)
{
	static char	*data;
	char		*line;
	int			err;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) == -1)
		return (NULL);
	if (!data)
	{
		data = ft_strdup("");
		if (!data)
			return (NULL);
	}
	line = get_data(fd, &data, &err);
	if (!line)
		return (free_null(&data));
	return (line);
}

char	*get_next_line2(int fd)
{
	static char	*data[FILES_LIMIT];
	char		*line;
	int			err;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) == -1)
	{
		if (fd > -1)
			return (free_null(&(data[fd])));
		return (NULL);
	}
	if (!data[fd])
	{
		data[fd] = ft_strdup("");
		if (!data[fd])
			return (NULL);
	}
	line = get_data(fd, &(data[fd]), &err);
	if (!line)
		return (free_null(&(data[fd])));
	return (line);
}

char	*get_next_line3(int fd, int *err)
{
	static char	*data[FILES_LIMIT];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) == -1)
	{
		if (fd > -1)
			return (*err = BAD_FD_ERR, free_null(&(data[fd])));
		else if (BUFFER_SIZE < 1)
			return (*err = BUFFER_ERR, NULL);
		return (*err = READ_ERR, NULL);
	}
	if (!data[fd])
	{
		data[fd] = ft_strdup("");
		if (!data[fd])
			return (*err = SYSTEM_ERR, NULL);
	}
	line = get_data(fd, &(data[fd]), err);
	if (!line)
		return (free_null(&(data[fd])));
	return (line);
}
