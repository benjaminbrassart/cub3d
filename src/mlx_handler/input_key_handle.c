/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_key_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:06:02 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/15 12:13:16 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

#include "cub.h"
#include "input.h"
#include "mlx_handle.h"

#include "mlx.h"

#include <math.h>
#include <stddef.h>
#include <X11/keysym.h>

static void	_move_player_x(t_player *player, int factor);
static void	_move_player_y(t_player *player, int factor);
static void	_move_player_yaw(t_player *player, int factor);

#include <stdio.h>

int	input_key_handle(int key, t_cub *cub)
{
	struct s_input const	*input = get_input(key);

	if (input == NULL)
		return (0);
	if (input->action.exits == EXIT)
		return (destroy_handle(cub));
	_move_player_x(&cub->player, input->action.factors.x);
	_move_player_y(&cub->player, input->action.factors.y);
	_move_player_yaw(&cub->player, input->action.factors.yaw);
	return (0);
}

static void	_move_player_x(t_player *player, int factor)
{
	player->x += factor * MOVEMENT_SPEED;
}

static void	_move_player_y(t_player *player, int factor)
{
	player->y += factor * MOVEMENT_SPEED;
}

static void	_move_player_yaw(t_player *player, int factor)
{
	player->yaw = fmodf(player->yaw + (factor * CAMERA_SPEED), M_PI * 2);
}
