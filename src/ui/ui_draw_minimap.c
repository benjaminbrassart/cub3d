/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:05:50 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/19 12:15:13 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "removeme.h"

#include "canvas.h"
#include "ui.h"

#include <math.h>

static void	_draw_player(t_cub *cub);
static void	_draw_map(t_cub *cub);

void	draw_minimap(t_cub *cub)
{
	_draw_map(cub);
	_draw_player(cub);
}

static void	_draw_player(t_cub *cub)
{
	t_shape const	player_circle = {.circle = {
		cub->player.x * (MM_TILE_SIZE + 1),
		cub->player.y * (MM_TILE_SIZE + 1),
		(MM_TILE_SIZE / 4)
	}};
	t_shape const	dirln = {.line = {
		cub->player.x * (MM_TILE_SIZE + 1),
		cos(cub->player.yaw) * (MM_TILE_SIZE * 1.5)
			+ (cub->player.x * (MM_TILE_SIZE + 1)),
		cub->player.y * (MM_TILE_SIZE + 1),
		sin(cub->player.yaw) * (MM_TILE_SIZE * 1.5)
			+ (cub->player.y * (MM_TILE_SIZE + 1)),
	}};

	canvas_draw_shape(&cub->screen, fill_circle, &player_circle, 0xFF00FF00);
	canvas_draw_shape(&cub->screen, draw_line, &dirln, 0xFFFFFFFF);
}

static void	_draw_map(t_cub *cub)
{
	int			x;
	int			y;
	t_shape		shape;

	y = 0;
	while (y < MAP_HEIGHT)
	{
		x = 0;
		while (g_map[y][x])
		{
			shape.rectangle = (struct s_rect){
				x * (MM_TILE_SIZE + 1), x * (MM_TILE_SIZE + 1) + MM_TILE_SIZE,
				y * (MM_TILE_SIZE + 1), y * (MM_TILE_SIZE + 1) + MM_TILE_SIZE,
			};
			canvas_draw_shape(&cub->screen, draw_rect, &shape,
				(0xFF << 24) | get_tile_color(g_map[y][x])->color);
			++x;
		}
		++y;
	}
}
