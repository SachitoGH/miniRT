/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:17:23 by dzapata           #+#    #+#             */
/*   Updated: 2024/04/15 19:31:02 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include "../Libft/headers/libft.h"

typedef struct s_hex
{
	unsigned long	number;
	int				bits;
	int				prefix;
	char			(*digit_case)(int);
}	t_hex;

int		ft_character(const int c, int fd);
char	ft_hex_digit_lower(int n);
char	ft_hex_digit_upper(int n);
int		ft_hex(t_hex *hex, int fd);
int		ft_integer(int number, int fd);
int		ft_octal(unsigned int number, int prefix, int fd);
int		ft_percentage(int fd);
int		ft_pointer(unsigned long ptr, int fd);
int		ft_printf(const char *s, ...);
int		ft_printf_fd(int fd, const char *s, ...);
int		ft_string(const char *s, int fd);
int		ft_uinteger(unsigned int number, int fd);

#endif
