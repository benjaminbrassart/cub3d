/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:44:55 by maxime            #+#    #+#             */
/*   Updated: 2022/05/18 14:51:05 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

typedef struct s_param
{
	char	*textures[4];
	int		*rgb[2];
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