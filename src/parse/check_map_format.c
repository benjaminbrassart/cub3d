/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 07:41:54 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/02 08:06:09 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cuberr.h"
#include "parse.h"

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
			if (cub->map[y][x] == '0')
			{
				if (y == 0 || y == cub->map_height - 1 || x == 0
					|| x == cub->map_lengths[y] - 1)
				{
					print_error("map", "not surrounded by walls");
					return (0);
				}
			}
			++x;
		}
		++y;
	}
	return (1);
}
