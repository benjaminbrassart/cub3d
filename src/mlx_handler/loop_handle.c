/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:11:05 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/16 15:14:23 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

#include "canvas.h"
#include "cub.h"
#include "input.h"
#include "mlx_handle.h"
#include "utils.h"

#include "ft.h"
#include "mlx.h"

#include <stddef.h>
#include <math.h>

static void	_move_player_x(t_player *player, int factor);
static void	_move_player_y(t_player *player, int factor);
static void	_move_player_yaw(t_player *player, int factor);
static void	factors_add(struct s_factors const *src, struct s_factors *dest);

static void	_draw_player(t_cub *cub)
{
	t_shape const	shape = {.rectangle = {
		cub->player.x - 10, cub->player.x + 10,
		cub->player.y - 10, cub->player.y + 10,
	}};
	t_shape const	dirpt = {.rectangle = {
		cos(cub->player.yaw) * 40 + cub->player.x - 5,
		cos(cub->player.yaw) * 40 + cub->player.x + 5,
		sin(cub->player.yaw) * 40 + cub->player.y - 5,
		sin(cub->player.yaw) * 40 + cub->player.y + 5,
	}};

	canvas_clear(&cub->screen);
	canvas_draw_shape(&cub->screen, draw_rect, &shape, 0xFF00FF00);
	canvas_draw_shape(&cub->screen, draw_rect, &dirpt, 0xFFFFFFFF);
}

int	loop_handle(t_cub *cub)
{
	size_t				n;
	struct s_factors	factors;
	float				multiplier;

	if (cub->screen.updated)
	{
		canvas_draw(cub, &cub->screen, 0, 0);
		cub->screen.updated = false;
	}
	ft_memset(&factors, 0, sizeof (factors));
	n = 0;
	multiplier = 1;
	while (n < (sizeof (g_inputs) / sizeof (*g_inputs)))
	{
		if (cub->player.input_mask & g_inputs[n].action.mask)
		{
			if (g_inputs[n].action.mask & INPUT_EXIT)
				return (destroy_handle(cub));
			if (g_inputs[n].action.mask & INPUT_SPRINT)
				multiplier = SPRINT_SPEED;
			else
				factors_add(&g_inputs[n].action.factors, &factors);
		}
		++n;
	}
	_move_player_yaw(&cub->player, factors.yaw);
	_move_player_x(&cub->player, factors.x * multiplier);
	_move_player_y(&cub->player, factors.y * multiplier);
	_draw_player(cub);
	return (0);
}

static void	_move_player_x(t_player *player, int factor)
{
	(void)player;
	(void)factor;
	// player->x += MOVEMENT_SPEED * factor * cos(player->yaw + factor * M_PI_2);
	// player->y -= MOVEMENT_SPEED * factor * sin(player->yaw + factor * M_PI_2);
	// player->x += factor * MOVEMENT_SPEED;
}

static void	_move_player_y(t_player *player, int factor)
{
	if (factor == 0)
		return ;
	player->x += factor * MOVEMENT_SPEED * cos(player->yaw + M_PI);
	player->y += factor * MOVEMENT_SPEED * sin(player->yaw + M_PI);
}

#include <stdio.h>

static void	_move_player_yaw(t_player *player, int factor)
{
	player->yaw = ft_modf(player->yaw + (factor * CAMERA_SPEED), M_PI * 2);
	printf("angle: %f %f deg\n", player->yaw, player->yaw * (180 / M_PI));
}

static void	factors_add(struct s_factors const *src, struct s_factors *dest)
{
	dest->x += src->x;
	dest->y += src->y;
	dest->yaw += src->yaw;
}

// struct s
// {
// 	int	i;
// 	void	*z;
// 	void (*fct)(int, struct s *ptr, t_cub *);
// };

// void	_hello_world(int a, struct s *ptr, t_cub *cub)
// {
// 	ptr->fct(a, ptr, cub);
// }

// void	a(t_cub *cub)
// {
// 	struct s p;

// 	p.fct = _hello_world;
// 	p.fct(10, &p, cub);
// }
