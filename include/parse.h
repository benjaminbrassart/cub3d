/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:44:55 by maxime            #+#    #+#             */
/*   Updated: 2022/06/02 13:21:08 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "cub.h"
# include "def.h"

# include <stddef.h>
# include <stdint.h>

# warning use macros for error messages

# define MAP_TILES			"NSWE01 "
# define MAP_FLOOR_TILES	"NSWE0"
# define MAP_PERS			"NSWE"

# define ERROR_TEXTURE		"Error\nWrong Texture\n"
# define ERROR_COLORS		"Error\nWrong Colors\n"
# define ERROR_IDENTIFIER	"Error\nWrong Identifier\n"
# define ERROR_MAP			"Error\nInvalid Map\n"

typedef struct s_lut_parser	t_lut_parser;

struct s_lut_parser
{
	char	*elem;
	size_t	length;
	int		(*func)(char const *, t_cub *, t_lut_parser const *);
	int		index;
};

int	texture(char const *line, t_cub *cub, t_lut_parser const *map);
int	color(char const *line, t_cub *cub, t_lut_parser const *map);

int	parse_map_content(t_cub *cub, int fd);
int	parse_map_params(t_cub *cub, int fd);

int	parse_map(t_cub *cub, int fd);

int	check_map_format(t_cub *cub);

static t_lut_parser const	g_lut_parser[] = {
{"NO", 2, texture, NORTH},
{"SO", 2, texture, SOUTH},
{"WE", 2, texture, WEST},
{"EA", 2, texture, EAST},
{"F", 1, color, COLOR_FLOOR},
{"C", 1, color, COLOR_CEILING},
{NULL, 0, NULL, -1},
};

#endif
