/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cuberr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:36:48 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/03 11:37:15 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBERR_H
# define CUBERR_H

# include "g_errno_name.h"

# include "def.h"

// # define ERROR_USAGE(prog, ext)		prog " <map." ext ">"
// # define ERROR_EXTENSION(ext)		"File extension must be " ext

# define ERROR_USAGE				"cub3d <map.cub>"
# define ERROR_EXTENSION			"File extension must be "

# define ERROR_INIT_DISPLAY			"Failed to initialize display"
# define ERROR_INIT_WINDOW			"Failed to initialize window"
# define ERROR_INIT_CANVAS			"Failed to initialize canvas"

# define ERROR_MAP_INVALID_TILE		"Invalid tile"
# define ERROR_MAP_NO_SPACE			"Not enough space"
# define ERROR_MAP_SURROUND			"Not surrounded by walls"
# define ERROR_MAP_HOLE				"Empty space next to floor"
# define ERROR_MAP_SPAWN_DUPLICATED	"Duplicated spawn"
# define ERROR_MAP_NO_SPAWN			"No spawn found"

# define ERROR_PARAM_INVALID		"Invalid identifier"
# define ERROR_PARAM_DUPLICATED		"Duplicated identifier"
# define ERROR_PARAM_MISSING		"Missing indentifier"

# define ERROR_COLOR_TRAILING		"Trailing character"
# define ERROR_COLOR_BOUNDS			"Value out of bounds"
# define ERROR_COLOR_FORMAT			"Invalid color format"

/**
 * Print a message on the standard error, followed by a newline
 *
 * format: "PROGNAME: prefix: msg"
 */
void	print_error(char const *prefix, char const *msg);
void	print_syserror(char const *prefix);

#endif
