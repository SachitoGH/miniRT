/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_extra.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 02:42:15 by dzapata           #+#    #+#             */
/*   Updated: 2025/04/22 04:09:05 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_EXTRA_H
# define LIBFT_EXTRA_H
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <limits.h>
# include "float.h"
# include "math.h"
# include "libft.h"
# include "libft_bonus.h"

int		ft_atoi2(const char *nptr, int *err) __attribute__((nonnull(2)));
double	ft_atof(char *str, char *dec_sep);
double	ft_atof2(char *str, char *dec_sep, int *err);
long	ft_atol(const char *nptr);
int		ft_char_in_str(char const *s1, char c);
char	*ft_dtoa(double num);
void	ft_dtoa2(double num, char *str);
void	ft_dtoa3(double num, char *str, int decimals);
char	*ft_ftoa(float num);
void	ft_ftoa2(float num, char *str);
void	ft_ftoa3(float num, char *str, int decimals);
int		ft_islowercase(char c);
int		ft_isspace(int c);
int		ft_isuppercase(char c);
void	ft_itoa2(int n, char *nbr);
int		ft_lstadd(t_list **last, void *content);
size_t	ft_tablelen(char **strs);
char	*ft_uitoa(unsigned int number);
int		free_code(void *ptr, int err_code);
void	*free_null(char **ptr);
void	free_ptr(void *ptr);
void	free_table(void **strs);
int		free_table_code(char **table, int err_code);
void	*free_table_ptr(void **table, void *ptr);
char	*free_strjoin1(char *s1, char *s2);
char	*free_strjoin2(char *s1, char *s2);
char	*free_strjoin3(char *s1, char *s2);
int		get_double_size(double num);
int		get_float_size(float num);
int		get_int_size(int n);
int		get_uint_size(unsigned int n);
int		hex_to_int(char *str);
char	*skip_spaces(char *str);

#endif