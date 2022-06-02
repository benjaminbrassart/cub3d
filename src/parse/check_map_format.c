/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 07:41:54 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/02 13:13:43 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cuberr.h"
#include "parse.h"

#include "ft.h"

static int	_is_ground(int c);

int	check_map_format(t_cub *cub)
{
	size_t	x;
	size_t	y;

	if (cub->map_height < 2)
	{
		print_error("map", "not enough space");
		return (0);
	}
	y = 0;
	while (y < cub->map_height)
	{
		x = 0;
		while (x < cub->map_lengths[y])
		{
			if (_is_ground(cub->map[y][x]))
			{
				if (y == 0 || y == cub->map_height - 1 || x == 0
					|| x == cub->map_lengths[y] - 1)
				{
					print_error("map", "not surrounded by walls");
					return (0);
				}
			}
			else if (cub->map[y][x] == ' ')
			{
				if (
					(x > 0 && _is_ground(cub->map[y][x - 1]))
					|| (x < cub->map_lengths[y] - 1 &&  _is_ground(cub->map[y][x + 1]))
					|| (y > 0 && x < cub->map_lengths[y - 1] && _is_ground(cub->map[y - 1][x]))
					|| (y < cub->map_height - 1 && x < cub->map_lengths[y + 1] && _is_ground(cub->map[y + 1][x]))
				)
				{
					print_error("map", "empty space next to floor");
					return (0);
				}
				cub->map[y][x] = '1';
			}
			++x;
		}
		++y;
	}
	return (1);
}

static int	_is_ground(int c)
{
	return (ft_strchr(MAP_FLOOR_TILES, c) != NULL);
}
