# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 09:52:29 by dzapata           #+#    #+#              #
#    Updated: 2024/04/14 14:31:12 by dzapata          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../Common.mk

#Variables =====================================================================

NAME		=	libftprintf.a

H_PRINTF	=	ft_printf.h

#Functions =======================================================================

$(NAME)		:	$(O_PRINTF)
				@ar -rcs $(NAME) $(O_PRINTF)
				@echo "The mandatory files have been added to" $(NAME)
				
%.o			:	%.c $(H_PRINTF)
				$(CC) -c $(CFLAGS) -I. $< -o $@

all			:	$(NAME)

clean		:
				@rm -f $(O_PRINTF)
				@echo $(NAME)": All object files have been removed"

fclean		:	clean
				@rm -f $(NAME)
				@echo $(NAME) "file has been removed"

re			:	fclean all

.PHONY		:	all, clean, fclean, re