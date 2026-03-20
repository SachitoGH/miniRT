# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Common.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/27 15:16:02 by dzapata           #+#    #+#              #
#    Updated: 2025/04/21 22:02:12 by dzapata          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables =====================================================================

MAKEFLAGS		=	--no-print-directory -r

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror

#Libft =========================================================================

C_LIB_DIR		=	mandatory

C_B_LIB_DIR		=	bonus

C_E_LIB_DIR		=	extra

C_B_LIBFT		=	ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstadd_front_bonus.c \
					ft_lstadd_back_bonus.c ft_lstlast_bonus.c ft_lstdelone_bonus.c \
					ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

C_LIBFT			=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
					ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
					ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
					ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c\
					ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
					ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
					ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

C_E_LIBFT		=	ft_isspace.c ft_char_in_str.c frees.c free_strjoin.c ft_uitoa.c \
					ft_lstadd.c ft_hex_to_int.c free_code.c ft_tablelen.c ft_atol.c \
					number_size.c ft_ftoa.c ft_itoa2.c free_ptr.c ft_dtoa.c ft_atoi2.c \
					skip_spaces.c ft_atof.c

O_LIB_DIR		=	$(addprefix $(C_LIB_DIR)/, $(C_LIBFT:.c=.o))

O_B_LIB_DIR		=	$(addprefix $(C_B_LIB_DIR)/, $(C_B_LIBFT:.c=.o))

O_E_LIB_DIR		=	$(addprefix $(C_E_LIB_DIR)/, $(C_E_LIBFT:.c=.o))

#Printf =========================================================================

C_PRINTF_DIR	=	ft_printf

C_PRINTF		=	ft_numbers.c ft_operations.c ft_printf.c ft_special.c ft_text.c

O_PRINTF		= 	$(C_PRINTF:.c=.o)

#Get Next Line ==================================================================

C_GNL_DIR		=	Get_Next_Line

C_GNL			=	get_next_line.c files.c

O_GNL			=	$(C_GNL:.c=.o)

.SUFFIXES		:
.SUFFIXES		:	.o .c .h