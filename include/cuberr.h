/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cuberr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:36:48 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/03 10:17:45 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBERR_H
# define CUBERR_H

# include "def.h"

# define ERROR_USAGE				"cub3d <map.cub>"
# define ERROR_EXTENSION			"File extension must be "

# define ERROR_INIT_DISPLAY			"failed to initialize display"
# define ERROR_INIT_WINDOW			"failed to initialize window"
# define ERROR_INIT_CANVAS			"failed to initialize canvas"

# define ERROR_MAP_NO_SPACE			"not enough space"
# define ERROR_MAP_SURROUND			"not surrounded by walls"
# define ERROR_MAP_HOLE				"empty space next to floor"
# define ERROR_MAP_SPAWN_DUPLICATED	"duplicated spawn"
# define ERROR_MAP_NO_SPAWN			"no spawn found"

# define ERROR_PARAM_DUPLICATED		"duplicated identifier"
# define ERROR_PARAM_MISSING		"missing indentifier"

# define ERROR_COLOR_TRAILING		"trailing character"
# define ERROR_COLOR_BOUNDS			"value out of bounds"
# define ERROR_COLOR_FORMAT			"invalid color format"

/**
 * Print a message on the standard error, followed by a newline
 *
 * format: "PROGNAME: prefix: msg"
 */
void	print_error(char const *prefix, char const *msg);

#endif
