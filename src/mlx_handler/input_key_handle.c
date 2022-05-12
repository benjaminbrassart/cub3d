/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_key_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:06:02 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/12 19:28:36 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

#include "cub.h"
#include "input.h"
#include "mlx_handle.h"

#include "mlx.h"

#include <math.h>
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
	if (input->exits)
		return (destroy_handle(cub));
	_move_player_x(&cub->player, input->factors.x);
	_move_player_y(&cub->player, input->factors.y);
	_move_player_yaw(&cub->player, input->factors.yaw);
	printf("%f\n", cub->player.yaw);
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
	float	yaw;

	yaw = player->yaw + (factor * CAMERA_SPEED);
	if (yaw < (-M_PI * 2))
		yaw += M_PI * 4;
	if (yaw > (M_PI * 2))
		yaw -= M_PI * 4;
	player->yaw = yaw;
}
