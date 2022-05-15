/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:11:05 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/15 12:55:30 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

#include "cub.h"
#include "input.h"
#include "mlx_handle.h"

#include "ft.h"
#include "mlx.h"

#include <stddef.h>
#include <math.h>

static void	_move_player_x(t_player *player, int factor);
static void	_move_player_y(t_player *player, int factor);
static void	_move_player_yaw(t_player *player, int factor);

void	factors_add(struct s_factors const *src, struct s_factors *dest)
{
	dest->x += src->x;
	dest->y += src->y;
	dest->yaw += src->yaw;
}

#include <stdio.h>

int	loop_handle(t_cub *cub)
{
	size_t				n;
	struct s_factors	factors;

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
	_move_player_x(&cub->player, factors.x);
	_move_player_y(&cub->player, factors.y);
	_move_player_yaw(&cub->player, factors.yaw);
	mlx_pixel_put(cub->mlx, cub->win, cub->player.x, cub->player.y, 0xFFFFFFFF);
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
