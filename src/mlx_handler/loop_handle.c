/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:11:05 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/17 16:50:31 by bbrassar         ###   ########.fr       */
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
static void	_factors_add(struct s_factors const *src, struct s_factors *dest);

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
			_factors_add(&g_inputs[n].action.factors, &factors);
		}
		++n;
	}
	_move_player_yaw(&cub->player, factors.yaw);
	_move_player_x(&cub->player, factors.x);
	_move_player_y(&cub->player, factors.y);
	cub_update(cub);
	return (0);
}

static bool	_check_collision(float x, float y, int factor)
{
	int const	xi = round(x + (0.5 * factor));
	int const	yi = round(y + (0.5 * factor));

	return ((yi >= 0 && yi < MAP_HEIGHT && xi >= 0
			&& (unsigned int)xi < ft_strlen(g_map[yi]) & g_map[yi][xi] != '1'));
}

static void	_move_player_x(t_player *player, int factor)
{
	float	x;
	float	y;

	if (factor == 0)
		return ;
	x = player->x + factor * MOVEMENT_SPEED * cos(player->yaw + M_PI_2);
	if (_check_collision(x, player->y, factor))
		player->x = x;
	y = player->y + factor * MOVEMENT_SPEED * sin(player->yaw + M_PI_2);
	if (_check_collision(player->x, y, factor))
		player->y = y;
}

static void	_move_player_y(t_player *player, int factor)
{
	float	x;
	float	y;

	if (factor == 0)
		return ;
	x = player->x + factor * MOVEMENT_SPEED * cos(player->yaw + M_PI);
	if (_check_collision(x, player->y, factor))
		player->x = x;
	y = player->y + factor * MOVEMENT_SPEED * sin(player->yaw + M_PI);
	if (_check_collision(player->x, y, factor))
		player->y = y;
}

static void	_move_player_yaw(t_player *player, int factor)
{
	player->yaw = ft_modf(player->yaw + (factor * CAMERA_SPEED), M_PI * 2);
}

static void	_factors_add(struct s_factors const *src, struct s_factors *dest)
{
	dest->x += src->x;
	dest->y += src->y;
	dest->yaw += src->yaw;
}
