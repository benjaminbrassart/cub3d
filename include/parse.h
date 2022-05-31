/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:44:55 by maxime            #+#    #+#             */
/*   Updated: 2022/05/30 12:16:20 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# define ERROR_TEXTURE "Error\nWrong Texture\n"
# define ERROR_COLORS "Error\nWrong Colors\n"
# define ERROR_IDENTIFIER "Error\nWrong Identifier\n"
# define ERROR_MAP "Error\nInvalid Map\n"

typedef struct s_param
{
	void		*textures[4];
	uint32_t	*rgb[2];
	char		*map;
}	t_param;

typedef struct s_map
{
	char	*elem;
	char	*img;
	int		(*func)(char *line, t_param *param, struct s_map *map);
	int		index;
}	t_map;


static t_map const	g_map[] = {
{"NO", texture, 0},
{"SO", texture, 1},
{"WE", texture, 2},
{"EA", texture, 3},
{"F", color, 0},
{"C", color, 1},
{NULL, NULL, NULL},
};

int		check_map(int fd);

#endif