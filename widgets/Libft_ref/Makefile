# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/27 15:11:32 by dzapata           #+#    #+#              #
#    Updated: 2024/08/16 20:29:17 by dzapata          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include Common.mk

#Variables =====================================================================

NAME		=	f_libft.a

O_LIB		=	$(O_LIB_DIR) $(O_E_LIB_DIR) $(O_B_LIB_DIR)

O_FILES		= 	$(addprefix Libft/, $(O_LIB)) \
				$(addprefix $(C_PRINTF_DIR)/, $(O_PRINTF)) \
				$(addprefix $(C_GNL_DIR)/, $(O_GNL))

#Functions =======================================================================

$(NAME)		:	$(O_FILES)
				@ar -rcs $(NAME) $(O_FILES)
				@echo $(NAME) "has been compiled"

all			:	$(NAME)

clean		:
				@$(MAKE) clean -C Libft/
				@$(MAKE) clean -C ft_printf/
				@$(MAKE) clean -C Get_Next_Line/

fclean		:
				@$(MAKE) fclean -C Libft/
				@$(MAKE) fclean -C ft_printf/
				@$(MAKE) fclean -C Get_Next_Line/
				@rm -f $(NAME)
				@echo $(NAME) "file has been removed"

re			:	fclean all

.PHONY		:	all, clean, fclean, re