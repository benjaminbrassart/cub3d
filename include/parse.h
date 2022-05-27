/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:44:55 by maxime            #+#    #+#             */
/*   Updated: 2022/05/27 19:46:12 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# define ERROR_TEXTURE "Error\n Wrong Texture"
# define ERROR_COLORS "Error\n Wrong Colors"
# define ERROR_IDENTIFIER "Error\n Wrong Identifier"
# define ERROR_MAP "Error\n Invalid Map"

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