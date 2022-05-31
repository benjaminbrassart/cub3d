/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:27:37 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/31 21:46:47 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

#include "cub.h"
#include "player.h"

#include <math.h>
#include <stdbool.h>

static void	_move_x(t_player *player, int x, float speed);
static void	_move_y(t_player *player, int y, float speed);
static bool	_check_collision(float move[2]);

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
		// if (!_check_collision(move))
		// 	return ;
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
		// if (!_check_collision(move))
		// 	return ;
		player->x = move[0];
		player->y = move[1];
	}
}

static bool	_check_collision(float move[2])
{
	int const	x[2] = {(int)(move[0] - PLAYER_HITBOX / 2),
					(int)(move[0] + PLAYER_HITBOX / 2)};
	int const	y[2] = {(int)(move[1] - PLAYER_HITBOX / 2),
					(int)(move[1] + PLAYER_HITBOX / 2)};
	int			i;
	int			j;

	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 2)
		{
			if (map_gettile(0, y[i], x[j]) == '1')
				return (false);
			++j;
		}
		++i;
	}
	return (true);
}
