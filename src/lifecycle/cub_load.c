/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:22:14 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/02 11:35:50 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "cuberr.h"
#include "def.h"
#include "lifecycle.h"
#include "parse.h"

#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int	cub_load(t_cub *cub)
{
	int	fd;
	int	res;

	fd = open(cub->map_file, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		print_error(cub->map_file, strerror(EISDIR));
		return (RES_FAILURE);
	}
	fd = open(cub->map_file, O_RDONLY);
	if (fd == -1)
	{
		print_error(cub->map_file, strerror(errno));
		return (RES_FAILURE);
	}
	res = parse_map(cub, fd);
	close(fd);
	return (res && check_map_format(cub) && cub_init_window(cub));
}
