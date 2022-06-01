/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:27:37 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/01 08:35:36 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

#include "cub.h"
#include "player.h"

#include <math.h>
#include <stdbool.h>

static void	_move_x(t_player *player, int x, float speed);
static void	_move_y(t_player *player, int y, float speed);

void	player_move(t_player *player, int x, int y)
{
	float	speed;

	speed = MOVEMENT_SPEED;
	if (x != 0 && y != 0)
		speed /= 1.5f;
	_move_x(player, x, speed);
	_move_y(player, y, speed);
}

static void	_move_x(t_player *player, int x, float speed)
{
	float	move[2];

	move[0] = player->x;
	move[1] = player->y;
	if (x != 0)
	{
		move[0] += x * speed * cos(player->yaw + M_PI_2);
		move[1] += x * speed * sin(player->yaw + M_PI_2);
		player->x = move[0];
		player->y = move[1];
	}
}

static void	_move_y(t_player *player, int y, float speed)
{
	float	move[2];

	move[0] = player->x;
	move[1] = player->y;
	if (y != 0)
	{
		move[0] += y * speed * cos(player->yaw + M_PI);
		move[1] += y * speed * sin(player->yaw + M_PI);
		player->x = move[0];
		player->y = move[1];
	}
}
