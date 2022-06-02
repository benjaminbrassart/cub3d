/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:27:37 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/02 15:12:34 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

#include "cub.h"

#include <math.h>
#include <stdbool.h>

static int	_check_collision(t_cub const *cub, float move_x, float move_y)
{
	if (map_gettile(cub, cub->player.x + move_x, cub->player.y + move_y) == '1')
		return (0);
	return (1);
}

void	player_move(t_cub *cub, float angle)
{
	float const	move_x = MOVEMENT_SPEED * cos(cub->player.yaw + angle);
	float const	move_y = MOVEMENT_SPEED * sin(cub->player.yaw + angle);

	if (_check_collision(cub, move_x, move_y))
	{
		cub->player.x += move_x;
		cub->player.y += move_y;
	}
}
