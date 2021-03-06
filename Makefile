# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 10:53:24 by bbrassar          #+#    #+#              #
#    Updated: 2022/06/03 16:03:26 by bbrassar         ###   ########.fr        #
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
							canvas/canvas_load.c \
							canvas/canvas_draw.c \
							canvas/canvas_draw_shape.c \
							canvas/canvas_getpx.c \
							canvas/canvas_setpx.c \
							canvas/draw/draw_rect.c \
							canvas/draw/draw_circle.c \
							canvas/draw/draw_line.c \
							canvas/draw/fill_rect.c \
							canvas/draw/fill_circle.c \
							lifecycle/cub_init.c \
							lifecycle/cub_load.c \
							lifecycle/cub_run.c \
							lifecycle/cub_update.c \
							lifecycle/cub_destroy.c \
							lifecycle/init/cub_init_display.c \
							lifecycle/init/cub_init_screen.c \
							lifecycle/init/cub_init_window.c \
							mlx_handler/loop_handle.c \
							mlx_handler/key_press_handle.c \
							mlx_handler/key_release_handle.c \
							mlx_handler/destroy_handle.c \
							map/map_gettile.c \
							map/map_checkline.c \
							player/player_move.c \
							player/player_rotate.c \
							parse/parse_map.c \
							parse/parse_map_params.c \
							parse/parse_map_content.c \
							parse/parse_color.c \
							parse/parse_texture.c \
							parse/check_map_format.c \
							raycasting/ray_init.c \
							raycasting/ray_cast.c \
							strlst/strlst_delete.c \
							strlst/strlst_push.c \
							strlst/strlst_toarray.c \
							ui/ui_draw_minimap.c \
							ui/ui_draw_background.c \
							ui/ui_draw_projection.c \
							ui/get_tile_color.c \
							utils/print_error.c \
							utils/get_input.c \
							utils/ft_modf.c \
							utils/swap.c \
							utils/rgb.c \
							utils/factors_add.c \
							utils/is_empty.c \
							utils/skip.c \
							utils/ft_isnonspace.c \
							utils/ft_strtrim_f.c \
							utils/errno_name.c
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

re:						fclean all

.PHONY:					all clean fclean re

.FORCE:
