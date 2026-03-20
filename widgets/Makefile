# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/11 08:38:07 by dzapata           #+#    #+#              #
#    Updated: 2025/03/31 21:54:16 by dzapata          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables =====================================================================

MAKEFLAGS	=	--no-print-directory

CC			=	cc

CFLAGS		=	-Wall -Wextra -MD

NAME		=	widgets.a

C_FILES		=	button.c label.c image.c draw_basics.c window.c spinner.c \
				drawable_text.c drawable_container.c mlx.c spinner_setters.c \
				drawable_container_getters.c default_widget.c widget_getters.c \
				drawable_text_setters.c drawable_text_getters.c draw_image.c \
				button_setters.c image_utils.c

ifeq ($(shell uname), Linux)
	C_FILES		+=	free_linux.c
else
	C_FILES		+=	free_mac.c
endif

H_DIR		=	headers

H_FILES		=	widgets.h

C_DIR		=	src

O_DIR		=	obj

O_F_DIR		=	$(addprefix $(O_DIR)/, $(C_FILES:.c=.o))

#Functions =====================================================================

$(NAME)		:	$(O_DIR) $(O_F_DIR)
				@ar -rcs $(NAME) $(O_F_DIR)
				@echo "$(NAME) has been compiled."

-include $(O_F_DIR:.o=.d)

$(O_DIR)	:
				@mkdir $(O_DIR)

$(O_DIR)/%.o:	$(C_DIR)/%.c
				$(CC) $(CFLAGS) -c $< -o $@

all			:	$(NAME)

clean		:
				@rm -fdr $(O_DIR)
				@echo $(NAME)": All object files have been removed"

fclean		:	clean
				@rm -f $(NAME)
				@echo $(NAME) "file has been removed"

re			:	fclean all

.PHONY		:	all, clean, fclean, re, check