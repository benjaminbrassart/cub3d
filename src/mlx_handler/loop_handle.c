/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:11:05 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/17 15:04:21 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "removeme.h" //! remove

#include "config.h"

#include "canvas.h"
#include "cub.h"
#include "input.h"
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

static void	_draw_hit(t_cub *cub)
{
	t_ray	ray;
	float	distance;
	t_shape	shape;
	t_vf2	pos;

	for (float i = -50; i <= 50; ++i)
	{
		ray_init(&ray, &cub->player, cub->player.yaw + (i / 100.0));
		if (ray_cast(&ray, &distance, &pos.x, &pos.y))
		{
			shape.circle = (struct s_circle){
				.x = (ray.start.x + ray.dir.x * distance) * (MM_TILE_SIZE + 1),
				.y = (ray.start.y + ray.dir.y * distance) * (MM_TILE_SIZE + 1),
				.radius = 12,
			};
			canvas_draw_shape(&cub->screen, draw_circle, &shape, 0xFFFFFF00);
			shape.circle.radius = 4;
			canvas_draw_shape(&cub->screen, fill_circle, &shape, 0xFFFFFF00);
			shape.line = (struct s_line){
				.x1 = ray.start.x * (MM_TILE_SIZE + 1), .x2 = (ray.start.x + ray.dir.x * distance) * (MM_TILE_SIZE + 1),
				.y1 = ray.start.y * (MM_TILE_SIZE + 1), .y2 = (ray.start.y + ray.dir.y * distance) * (MM_TILE_SIZE + 1),
			};
			canvas_draw_shape(&cub->screen, draw_line, &shape, 0xFFFF0000);
		}
	}
}

static void	_draw_map(t_cub *cub)
{
	int			x;
	int			y;
	uint32_t	color;
	t_shape		shape;

	y = 0;
	while (y < MAP_HEIGHT)
	{
		x = 0;
		while (g_map[y][x])
		{
			switch (g_map[y][x])
			{
				case '0':
					color = 0xFFFF00FF; break;
				case '1':
					color = 0xFF888888; break;
				case 'W':
				case 'E':
				case 'N':
				case 'S':
					color = 0xFFFFFFFF; break;
				default:
					color = 0xFF888888; break;
			}
			shape.rectangle.x1 = x * (MM_TILE_SIZE + 1);
			shape.rectangle.x2 = x * (MM_TILE_SIZE + 1) + MM_TILE_SIZE;
			shape.rectangle.y1 = y * (MM_TILE_SIZE + 1);
			shape.rectangle.y2 = y * (MM_TILE_SIZE + 1) + MM_TILE_SIZE;
			canvas_draw_shape(&cub->screen, draw_rect, &shape, color);
			++x;
		}
		++y;
	}
}

static void	_draw_player(t_cub *cub)
{
	t_shape const	player_circle = {.circle = {
		cub->player.x * (MM_TILE_SIZE + 1),
		cub->player.y * (MM_TILE_SIZE + 1),
		(MM_TILE_SIZE / 4)
	}};
	// t_shape const	shape = {.rectangle = {
	// 	cub->player.x * (MM_TILE_SIZE + 1) - (MM_TILE_SIZE / 4), cub->player.x * (MM_TILE_SIZE + 1) + (MM_TILE_SIZE / 4),
	// 	cub->player.y * (MM_TILE_SIZE + 1) - (MM_TILE_SIZE / 4), cub->player.y * (MM_TILE_SIZE + 1) + (MM_TILE_SIZE / 4),
	// }};
	// t_shape const	dirpt = {.line = {
	// 	cos(cub->player.yaw) * 40 + (cub->player.x * (MM_TILE_SIZE + 1)) - 5,
	// 	cos(cub->player.yaw) * 40 + (cub->player.x * (MM_TILE_SIZE + 1)) + 5,
	// 	sin(cub->player.yaw) * 40 + (cub->player.y * (MM_TILE_SIZE + 1)) - 5,
	// 	sin(cub->player.yaw) * 40 + (cub->player.y * (MM_TILE_SIZE + 1)) + 5,
	// }};
	t_shape const	dirln = {.line = {
		cub->player.x * (MM_TILE_SIZE + 1), cos(cub->player.yaw) * 40 + (cub->player.x * (MM_TILE_SIZE + 1)),
		cub->player.y * (MM_TILE_SIZE + 1), sin(cub->player.yaw) * 40 + (cub->player.y * (MM_TILE_SIZE + 1)),
	}};

	canvas_draw_shape(&cub->screen, fill_circle, &player_circle, 0xFF00FF00);
	canvas_draw_shape(&cub->screen, draw_line, &dirln, 0xFFFFFFFF);
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
				_factors_add(&g_inputs[n].action.factors, &factors);
		}
		++n;
	}
	_move_player_yaw(&cub->player, factors.yaw);
	_move_player_x(&cub->player, factors.x * multiplier);
	_move_player_y(&cub->player, factors.y * multiplier);
	canvas_clear(&cub->screen);
	_draw_map(cub);
	// _draw_hit(cub);
	(void)_draw_hit;
	_draw_player(cub);
	return (0);
}

static bool	_check_collision(float x, float y, int factor)
{
	int const xi = round(x + (0.5 * factor));
	int const yi = round(y + (0.5 * factor));

	return ((yi >= 0 && yi < MAP_HEIGHT && xi >= 0
			&& (unsigned int)xi < ft_strlen(g_map[yi]) & g_map[yi][xi] != '1'));
}

static void	_move_player_x(t_player *player, int factor)
{
	float	x;
	float	y;

	if (factor == 0)
		return ;
	x = player->x + factor * MOVEMENT_SPEED * cos(player->yaw + M_PI / 2);
	if (_check_collision(x, player->y, factor))
		player->x = x;
	y = player->y + factor * MOVEMENT_SPEED * sin(player->yaw + M_PI / 2);
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
