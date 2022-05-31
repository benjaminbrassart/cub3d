/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:22:14 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/01 00:39:37 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "cuberr.h"
#include "def.h"
#include "lifecycle.h"

#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

// TODO parsing
static int	__load(t_cub *cub)
{
	cub->colors[COLOR_CEILING] = 0xAADDFF;
	cub->colors[COLOR_FLOOR] = 0xFFAA00;
	if (
		canvas_load(cub, "textures/north.xpm", &cub->textures[NORTH])
		&& canvas_load(cub, "textures/south.xpm", &cub->textures[SOUTH])
		&& canvas_load(cub, "textures/west.xpm", &cub->textures[WEST])
		&& canvas_load(cub, "textures/east.xpm", &cub->textures[EAST])
	)
		return (RES_SUCCESS);
	print_error("textures", "failed to load debug textures");
	return (RES_FAILURE);
}

int	cub_load(t_cub *cub)
{
	int	fd;
	int	res;

	return (__load(cub) && cub_init_window(cub));
	fd = open(cub->map_file.path, O_RDONLY);
	if (fd == -1)
	{
		print_error(cub->map_file.path, strerror(errno));
		return (RES_FAILURE);
	}
	cub->map_file.fd = fd;
	res = __load(cub);
	close(fd);
	return (RES_SUCCESS);
}
