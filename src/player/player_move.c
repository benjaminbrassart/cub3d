/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:27:37 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/26 13:28:46 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

#include "player.h"

#include <math.h>

void	player_move(t_player *player, int x, int y)
{
	if (x != 0)
	{
		player->x += x * MOVEMENT_SPEED * cos(player->yaw + M_PI_2);
		player->y += x * MOVEMENT_SPEED * sin(player->yaw + M_PI_2);
	}
	if (y != 0)
	{
		player->x += y * MOVEMENT_SPEED * cos(player->yaw + M_PI);
		player->y += y * MOVEMENT_SPEED * sin(player->yaw + M_PI);
	}
}
