/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_draw_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:05:50 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/01 08:43:55 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "removeme.h"

#include "canvas.h"
#include "ui.h"

#include "mlx.h"

#include <math.h>

static void	_draw_direction(t_cub *cub);
static void	_draw_player(t_cub *cub);
static void	_draw_map(t_cub *cub);

void	ui_draw_minimap(t_cub *cub)
{
	_draw_map(cub);
	_draw_player(cub);
}

static void	_draw_player(t_cub *cub)
{
	t_shape const	player_circle = {.circle = {
		cub->player.x * (MM_TILE_SIZE + 1),
		cub->player.y * (MM_TILE_SIZE + 1),
		(MM_TILE_SIZE / 2)
	}};

	_draw_direction(cub);
	canvas_draw_shape(&cub->screen, fill_circle, &player_circle, 0xFFFFFFFF);
}

static void	_draw_map(t_cub *cub)
{
	size_t		x;
	size_t		y;
	t_shape		shape;

	y = 0;
	while (y < cub->map_height)
	{
		x = 0;
		while (cub->map[y][x])
		{
			shape.rectangle = (struct s_rect){
				x * (MM_TILE_SIZE + 1), x * (MM_TILE_SIZE + 1) + MM_TILE_SIZE,
				y * (MM_TILE_SIZE + 1), y * (MM_TILE_SIZE + 1) + MM_TILE_SIZE,
			};
			canvas_draw_shape(&cub->screen, draw_rect, &shape,
				get_tile_color(cub->map[y][x])->color);
			++x;
		}
		++y;
	}
}

static void	_draw_direction(t_cub *cub)
{
	t_shape const	dirln = {.line = {
		cub->player.x * (MM_TILE_SIZE + 1),
		cos(cub->player.yaw) * (MM_TILE_SIZE * 1.5)
		+ (cub->player.x * (MM_TILE_SIZE + 1)),
		cub->player.y * (MM_TILE_SIZE + 1),
		sin(cub->player.yaw) * (MM_TILE_SIZE * 1.5)
		+ (cub->player.y * (MM_TILE_SIZE + 1)),
	}};

	canvas_draw_shape(&cub->screen, draw_line, &dirln, 0x000000);
}
