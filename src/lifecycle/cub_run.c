/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:13:58 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/19 12:34:51 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "removeme.h" //! remove

#include "canvas.h"
#include "cuberr.h"
#include "def.h"
#include "lifecycle.h"

#include "ft.h"
#include "mlx.h"

#include <math.h>

char const	*_get_spawn_tile(float *x_ptr, float *y_ptr)
{
	int			y;
	char const	*tile_ptr;

	*x_ptr = -1;
	*y_ptr = -1;
	y = 0;
	while (y < MAP_HEIGHT)
	{
		tile_ptr = g_map[y];
		while (1)
		{
			tile_ptr = ft_strpbrk(tile_ptr, "NSWE");
			if (tile_ptr == NULL)
				break ;
			if (*x_ptr != -1 || *y_ptr != -1)
				return (NULL);
			*x_ptr = tile_ptr - g_map[y];
			*y_ptr = y;
			++tile_ptr;
		}
		++y;
	}
	if (*x_ptr == -1 || *y_ptr == -1)
		return (NULL);
	return (&g_map[(int)*y_ptr][(int)*x_ptr]);
}

int	cub_run(t_cub *cub)
{
	char const	*spawn_tile = _get_spawn_tile(&cub->player.x, &cub->player.y);
	int			m;

	if (spawn_tile == NULL)
	{
		print_error("map", "unable to find unique spawn");
		return (RES_FAILURE);
	}
	m = 0;
	while ("ESWN"[m] != *spawn_tile)
		++m;
	cub->player.yaw = m * M_PI_2;
	cub->player.x += 0.5;
	cub->player.y += 0.5;
	mlx_loop(cub->mlx);
	return (RES_SUCCESS);
}
