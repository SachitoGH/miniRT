# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/06 05:44:00 by dzapata           #+#    #+#              #
#    Updated: 2024/08/16 20:26:02 by dzapata          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../Common.mk

#Variables =====================================================================

NAME		=	get_next_line.a

H_GNL		=	get_next_line.h

#Functions =======================================================================

$(NAME)		:	$(O_GNL)
				@ar -rcs $(NAME) $(O_GNL)
				@echo "All the files have been added to" $(NAME)
				
%.o			:	%.c $(H_GNL)
				$(CC) -c $(CFLAGS) -I. $< -o $@

all			:	$(NAME)

clean		:
				@rm -f $(O_GNL)
				@echo $(NAME)": All object files have been removed"

fclean		:	clean
				@rm -f $(NAME)
				@echo $(NAME) "file has been removed"

re			:	fclean all

.PHONY		:	all clean fclean re