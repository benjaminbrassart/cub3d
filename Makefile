# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 10:53:24 by bbrassar          #+#    #+#              #
#    Updated: 2022/05/12 11:08:59 by bbrassar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= cub3d

CC						= cc
CFLAGS					+= -Wall
CFLAGS					+= -Werror
CFLAGS					+= -Wextra
CFLAGS					+= -c
CFLAGS					+= -MMD -MP
CFLAGS					+= -Iinclude

RM						= rm -f

DIR_SRC					= src
DIR_OBJ					= obj

SRC						= main.c
OBJ						= $(SRC:%.c=$(DIR_OBJ)/%.o)
DEP						= $(OBJ:.o=.d)

$(NAME):				$(OBJ)
						$(CC) $^ -o $@ $(LDFLAGS) $(LDLIBS)

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
