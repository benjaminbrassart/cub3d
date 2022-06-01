# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msainton <msainton@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 10:53:24 by bbrassar          #+#    #+#              #
#    Updated: 2022/05/31 12:02:50 by msainton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= cub3d

DIR_LIBFT				= libft
DIR_MLX					= minilibx-linux

NAME_LIBFT				= $(DIR_LIBFT)/libft.a
NAME_MLX				= $(DIR_MLX)/libmlx.a

NAME_LIBS				+= $(NAME_LIBFT)
NAME_LIBS				+= $(NAME_MLX)

CC						= cc
CFLAGS					+= -Wall
CFLAGS					+= -Werror
CFLAGS					+= -Wextra
CFLAGS					+= -c
CFLAGS					+= -MMD -MP
CFLAGS					+= -Iinclude
CFLAGS					+= -I$(DIR_LIBFT)
CFLAGS					+= -I$(DIR_MLX)
CFLAGS					+= -Iinclude
CFLAGS					+= -I.

# TODO remove when deploying
DEBUG					= true

ifeq ($(DEBUG), true)
CFLAGS					+= -g3
endif

LDLIBS					+= -lft
LDLIBS					+= -lmlx
LDLIBS					+= -lm
LDLIBS					+= -lXext
LDLIBS					+= -lX11

LDFLAGS					+= -L$(DIR_LIBFT)
LDFLAGS					+= -L$(DIR_MLX)

RM						= rm -f

DIR_SRC					= src
DIR_OBJ					= obj

SRC						= main.c \
							args/args_check.c \
							canvas/canvas_clear.c \
							canvas/canvas_destroy.c \
							canvas/canvas_draw.c \
							canvas/canvas_draw_shape.c \
							canvas/canvas_setpx.c \
							canvas/draw/draw_rect.c \
							canvas/draw/draw_circle.c \
							canvas/draw/draw_line.c \
							canvas/draw/fill_rect.c \
							canvas/draw/fill_circle.c \
							lifecycle/cub_init.c \
							lifecycle/cub_load.c \
							lifecycle/cub_run.c \
							lifecycle/cub_destroy.c \
							mlx_handler/loop_handle.c \
							mlx_handler/key_press_handle.c \
							mlx_handler/key_release_handle.c \
							mlx_handler/destroy_handle.c \
							parse/parse_elem.c \
							parse/parse_utils.c	\
							parse/parse.c \
							utils/print_error.c \
							utils/get_input.c \
							utils/ft_modf.c	\
							utils/swap.c \
							utils/rgb.c
OBJ						= $(SRC:%.c=$(DIR_OBJ)/%.o)
DEP						= $(OBJ:.o=.d)

$(NAME):				$(NAME_LIBS) $(OBJ)
						@printf -- '\033[33m$(CC) $(filter %.o,$^) -o $@ $(LDFLAGS) $(LDLIBS)\033[0m\n'
						@$(CC) $(filter %.o,$^) -o $@ $(LDFLAGS) $(LDLIBS)

$(NAME_LIBS):			.FORCE
						@$(MAKE) -C $(@D)

$(DIR_OBJ)/%.o:			$(DIR_SRC)/%.c
						@mkdir -p $(@D)
						@printf -- '\033[34m$(CC) $(CFLAGS) $< -o $@\033[0m\n'
						@$(CC) $(CFLAGS) $< -o $@

-include $(DEP)

all:					$(NAME)

clean:
						$(RM) -r $(DIR_OBJ)

fclean:					clean
						$(RM) $(NAME)
						$(MAKE) -C $(DIR_LIBFT) fclean
						$(MAKE) -C $(DIR_MLX) clean

re:						fclean all

.PHONY:					all clean fclean re

.FORCE:
