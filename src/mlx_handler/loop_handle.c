/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:11:05 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/23 16:54:23 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "removeme.h" //! remove

#include "config.h"

#include "canvas.h"
#include "cub.h"
#include "input.h"
#include "lifecycle.h"
#include "mlx_handle.h"
#include "ray.h"
#include "utils.h"

#include "ft.h"
#include "mlx.h"

#include <stddef.h>
#include <math.h>

static void	_move_player(t_player *player, int x, int y);
static void	_move_player_cam(t_player *player, int yaw, int pitch);

int	loop_handle(t_cub *cub)
{
	size_t				n;
	struct s_factors	factors;

	if (cub->screen.updated)
	{
		canvas_draw(cub, &cub->screen, 0, 0);
		cub->screen.updated = false;
	}
	ft_memset(&factors, 0, sizeof (factors));
	n = 0;
	while (n < (sizeof (g_inputs) / sizeof (*g_inputs)))
	{
		if (cub->player.input_mask & g_inputs[n].action.mask)
		{
			if (g_inputs[n].action.mask & INPUT_EXIT)
				return (destroy_handle(cub));
			factors_add(&g_inputs[n].action.factors, &factors);
		}
		++n;
	}
	_move_player_cam(&cub->player, factors.yaw, factors.pitch);
	_move_player(&cub->player, factors.x, factors.y);
	cub_update(cub);
	return (0);
}

static void	_move_player(t_player *player, int x, int y)
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

static void	_move_player_cam(t_player *player, int yaw, int pitch)
{
	if (yaw != 0)
		player->yaw = ft_modf(player->yaw + (yaw * CAMERA_SPEED), M_PI * 2);
	if (pitch != 0)
		player->pitch = player->pitch + (pitch * CAMERA_SPEED);
	if (player->pitch > M_PI)
		player->pitch = M_PI;
	if (player->pitch < 0)
		player->pitch = 0;
}
