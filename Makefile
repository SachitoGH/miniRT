# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/11 08:38:07 by dzapata           #+#    #+#              #
#    Updated: 2025/05/27 16:52:58 by dzapata          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables =====================================================================

MAKEFLAGS	=	--no-print-directory

CC			=	cc

CFLAGS		=	-Wall -Wextra -MD

NAME		=	miniRT

MLX_C_FLAGS =	-I $(MLX_DIR)

C_FILES		=	main.c miniRT.c panel_control.c draw_values.c set_events.c \
				clean.c buttons_events.c panel_general.c default_values.c \
				link_spinners.c number_spinner.c get_strings.c utils.c floats.c\
				click_checker.c preloaded_is.c verify_3dobjects.c verify_objects.c \
				parser.c verify_helpers.c parse_objects.c parse_3dobjects.c \
				parse_helpers.c integers.c error.c fvec3_operations.c color.c\
				fvec3_operations2.c hit_object3d.c render.c patterns.c \
				fvec3_operations3.c relink.c movements.c normals.c calculations.c \
				select_object.c verifier.c default_odata.c default_pdata.c \
				preloaded_get.c fvec4_operations.c fvec4_operations2.c \
				fvec4_operations3.c fvec4_operations4.c matrix.c matrix_inverse.c \
				transformations.c calculations_camera.c hit_helpers.c \
				render2.c render3.c matrix_init.c hooks.c draw_helpers.c

ifeq ($(shell uname), Linux)
	MLX_DIR		=	minilibx
	MLX_O_FLAGS	=	-L $(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
	MLX_LIB		=	$(MLX_DIR)/libmlx_Linux.a
else
	MLX_DIR		=	minilibx_macos
	MLX_O_FLAGS	=	-L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
	MLX_LIB		=	$(MLX_DIR)/libmlx.a
endif

LIBFT_DIR	=	Libft_ref

LIBFT		=	$(LIBFT_DIR)/f_libft.a

WIDGETS_DIR	=	widgets

WIDGETS		=	$(WIDGETS_DIR)/widgets.a

H_DIR		=	headers

H_FILES		=	miniRT.h constants.h widgets.h dimensions.h\
				constants_linux.h constants_mac.h

H_F_DIR		=	$(addprefix $(H_DIR)/, $(H_FILES))

C_DIR		=	src

C_F_DIR		=	$(addprefix $(C_DIR)/, $(C_FILES))

O_DIR		=	obj

O_F_DIR		=	$(addprefix $(O_DIR)/, $(C_FILES:.c=.o))

#Functions =====================================================================

$(NAME)		:	$(MLX_LIB) $(LIBFT) $(WIDGETS) $(O_DIR) $(O_F_DIR)
				@$(CC) $(O_F_DIR) $(LIBFT) $(WIDGETS) $(MLX_O_FLAGS) -o $(NAME)
				@echo "$(NAME) has been compiled."

-include $(O_F_DIR:.o=.d)

$(O_DIR)	:	
				@mkdir $(O_DIR)

$(O_DIR)/%.o:	$(C_DIR)/%.c
				$(CC) $(CFLAGS) $(MLX_C_FLAGS) -c $< -o $@

$(LIBFT)	:	check
				@$(MAKE) all -C $(LIBFT_DIR)

$(MLX_LIB)	:	check
				@$(MAKE) -C $(MLX_DIR)

$(WIDGETS)	:	check
				@$(MAKE) all -C $(WIDGETS_DIR)

check		:

all			:	$(NAME)

clean		:
				@rm -fdr $(O_DIR)
				@echo $(NAME)": All object files have been removed"

fclean		:
				@$(MAKE) fclean -C $(LIBFT_DIR)
				@$(MAKE) fclean -C $(WIDGETS_DIR)
				@rm -fdr $(O_DIR)
				@echo $(NAME)": All object files have been removed"
				@$(MAKE) clean -C $(MLX_DIR)
				@rm -f $(NAME)
				@echo $(NAME) "file has been removed"

re			:	fclean all

.PHONY		:	all, clean, fclean, re, check