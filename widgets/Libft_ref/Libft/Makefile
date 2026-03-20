# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 09:52:29 by dzapata           #+#    #+#              #
#    Updated: 2024/04/12 18:14:32 by dzapata          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../Common.mk

#Variables =====================================================================

NAME		=	libft.a

H_DIR		=	headers

H_FILES		=	$(H_DIR)/libft.h $(H_DIR)/libft_extra.h 

H_BONUS		=	$(H_DIR)/libft_bonus.h

#Functions =======================================================================

$(NAME)			:	$(O_LIB_DIR) $(O_E_LIB_DIR)
					@ar -rcs $(NAME) $^
					@echo "The mandatory files have been added to" $(NAME)

%.o				:	%.c $(H_FILES)
					$(CC) $(CFLAGS) -c $< -o $@

all				:	$(NAME)

bonus			:	$(NAME) $(O_B_LIB_DIR)
					@ar -rcs $(NAME) $^
					@echo "The bonus files have been added to" $(NAME)

clean			:
					@rm -f $(O_LIB_DIR) $(O_E_LIB_DIR) $(O_B_LIB_DIR)
					@echo $(NAME)": All object files have been removed"

fclean			:	clean
					@rm -f $(NAME)
					@echo $(NAME) "file has been removed"

re				: 	fclean all

.PHONY			:	all, clean, fclean, re, bonus