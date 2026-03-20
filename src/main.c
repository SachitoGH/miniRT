/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 21:09:18 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/18 19:07:56 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

int	check_file(char *path, char *extension)
{
	int	path_len;
	int	ex_len;

	path_len = ft_strlen(path);
	ex_len = ft_strlen(extension);
	return (path_len >= ex_len
		&& !ft_strncmp(&path[path_len - ex_len], extension, ex_len));
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		ft_printf_fd(STDERR_FILENO, "Error: Bad number of arguments\n");
		return (EXIT_FAILURE);
	}
	if (!check_file(argv[1], FILE_EXT))
	{
		ft_printf_fd(STDERR_FILENO,
			"Error: The file must have the '" FILE_EXT "' extension.\n");
		return (EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (perror("Error"), EXIT_FAILURE);
	return (minirt(fd, DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT));
	return (0);
}
