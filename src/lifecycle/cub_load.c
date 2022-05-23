/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:22:14 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/20 12:41:37 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	(void)cub;
	return (RES_FAILURE);
}

int	cub_load(t_cub *cub)
{
	int	fd;
	int	res;

	cub->colors[COLOR_CEILING] = 0xAADDFF;
	cub->colors[COLOR_FLOOR] = 0xAAFFAA;
	return (RES_SUCCESS);
	fd = open(cub->map_file.path, O_RDONLY);
	if (fd == -1)
	{
		print_error(cub->map_file.path, strerror(errno));
		return (RES_FAILURE);
	}
	cub->map_file.fd = fd;
	res = __load(cub);
	close(fd);
	return (res);
}
