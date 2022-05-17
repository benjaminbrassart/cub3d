/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:37:07 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/17 16:43:41 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "removeme.h"

#include "canvas.h"
#include "cub.h"
#include "lifecycle.h"
#include "ray.h"

#include <math.h>

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

void	cub_update(t_cub *cub)
{
	canvas_clear(&cub->screen);
	_draw_map(cub);
	// _draw_hit(cub);
	(void)_draw_hit;
	_draw_player(cub);
}
