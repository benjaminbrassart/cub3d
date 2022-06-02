# **************************************************************************** #
#                                       #
#                             :::   ::::::::  #
#  Makefile                      :+:   :+:  :+:  #
#                           +:+ +:+     +:+   #
#  By: bbrassar <bbrassar@student.42.fr>     +#+ +:+    +#+     #
#                         +#+#+#+#+#+  +#+      #
#  Created: 2021/05/20 12:54:24 by bbrassar     #+#  #+#       #
#  Updated: 2022/04/05 22:53:01 by bbrassar     ###  ########.fr    #
#                                       #
# **************************************************************************** #

NAME				= libft.a

CC					= cc
CFLAGS				= -Wall -Wextra -Werror -c -MMD -MP -I. -Iprivate

AR					= ar
ARFLAGS				= rs

RM					= rm -f

ifeq ($(DEBUG), true)
CFLAGS				+= -g3
endif

DIR_SRC				= src
DIR_OBJ				= obj

SRC					= \
						ft_memset.c \
						ft_memcpy.c \
						ft_memccpy.c \
						ft_memmove.c \
						ft_memchr.c \
						ft_memcmp.c \
						ft_strlen.c \
						ft_isalpha.c \
						ft_isdigit.c \
						ft_isalnum.c \
						ft_isascii.c \
						ft_isprint.c \
						ft_isspace.c \
						ft_toupper.c \
						ft_tolower.c \
						ft_strchr.c \
						ft_strrchr.c \
						ft_strncmp.c \
						ft_strlcpy.c \
						ft_strlcat.c \
						ft_strnstr.c \
						ft_atoi.c \
						ft_calloc.c \
						ft_strdup.c \
						ft_substr.c \
						ft_strjoin.c \
						ft_strtrim.c \
						ft_split.c \
						ft_itoa.c \
						ft_strnlen.c \
						ft_strndup.c \
						ft_strtoi.c \
						ft_strcmp.c \
						ft_strcspn.c \
						ft_strspn.c \
						ft_strstr.c \
						ft_strrstr.c \
						ft_strpbrk.c \
						get_next_line.c

OBJ					= $(addprefix $(DIR_OBJ)/, $(SRC:.c=.o))
DEP					= $(OBJ:.o=.d))

$(NAME):			$(OBJ)
					$(AR) $(ARFLAGS) $@ $?

-include $(DEP)

$(DIR_OBJ)/%.o:		$(DIR_SRC)/%.c
					@mkdir -p $(@D)
					$(CC) $(CFLAGS) $< -o $@

all:				$(NAME)

clean:
					$(RM) $(OBJ)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re
