# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 10:53:24 by bbrassar          #+#    #+#              #
#    Updated: 2022/05/12 11:22:01 by bbrassar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= cub3d
NAME_LIBFT				= libft/libft.a
NAME_MLX				= minilibx-linux/libmlx.a

NAME_LIBS				= $(NAME_LIBFT) $(NAME_MLX)

CC						= cc
CFLAGS					+= -Wall
CFLAGS					+= -Werror
CFLAGS					+= -Wextra
CFLAGS					+= -c
CFLAGS					+= -MMD -MP
CFLAGS					+= -Iinclude

LDLIBS					+= -lft
LDLIBS					+= -lmlx
LDLIBS					+= -lm
LDFLAGS					+= -L$(dir $(NAME_LIBFT))
LDFLAGS					+= -L$(dir $(NAME_MLX))

RM						= rm -f

DIR_SRC					= src
DIR_OBJ					= obj

SRC						= main.c
OBJ						= $(SRC:%.c=$(DIR_OBJ)/%.o)
DEP						= $(OBJ:.o=.d)

$(NAME):				$(NAME_LIBS) $(OBJ)
						$(CC) $(filter %.o,$^) -o $@ $(LDFLAGS) $(LDLIBS)

$(NAME_LIBS):			.FORCE
						$(MAKE) -C $(@D)

$(DIR_OBJ)/%.o:			$(DIR_SRC)/%.c
						@mkdir -p $(@D)
						$(CC) $(CFLAGS) $< -o $@

-include $(DEP)

all:					$(NAME)

clean:
						$(RM) -r $(DIR_OBJ)

fclean:					clean
						$(RM) $(NAME)

re:						fclean all

.PHONY:					all clean fclean re

.FORCE:
