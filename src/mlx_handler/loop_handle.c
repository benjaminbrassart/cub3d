/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:11:05 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/19 13:16:28 by bbrassar         ###   ########.fr       */
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

static void	_move_player_x(t_player *player, int factor);
static void	_move_player_y(t_player *player, int factor);
static void	_move_player_yaw(t_player *player, int factor);

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
	_move_player_yaw(&cub->player, factors.yaw);
	_move_player_x(&cub->player, factors.x);
	_move_player_y(&cub->player, factors.y);
	cub_update(cub);
	return (0);
}

static void	_move_player_x(t_player *player, int factor)
{
	if (factor == 0)
		return ;
	player->x += factor * MOVEMENT_SPEED * cos(player->yaw + M_PI_2);
	player->y += factor * MOVEMENT_SPEED * sin(player->yaw + M_PI_2);
}

static void	_move_player_y(t_player *player, int factor)
{
	if (factor == 0)
		return ;
	player->x += factor * MOVEMENT_SPEED * cos(player->yaw + M_PI);
	player->y += factor * MOVEMENT_SPEED * sin(player->yaw + M_PI);
}

static void	_move_player_yaw(t_player *player, int factor)
{
	if (factor != 0)
		player->yaw = ft_modf(player->yaw + (factor * CAMERA_SPEED), M_PI * 2);
}
