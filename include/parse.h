/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:44:55 by maxime            #+#    #+#             */
/*   Updated: 2022/05/16 12:13:22 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

typedef struct s_param
{
	char	*direction;
	char	*img;
}	t_param;

typedef struct s_map
{
	char	*elem;
	char	*img;
	int		(*func)(char *line, t_param *param);
}	t_map;


static t_map const	g_map[] = {
{"NO", path_to_the_north_texture, texture},
{"SO", path_to_the_south_texture, texture},
{"WE", path_to_the_west_texture, texture},
{"EA", path_to_the_east_texture, texture},
{"F", RGB, color},
{"C", RGB, color},
};

int		check_map(int fd);

#endif