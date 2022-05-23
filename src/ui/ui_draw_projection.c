/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_draw_projection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:15:35 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/23 03:35:05 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

#include "canvas.h"
#include "ray.h"
#include "ui.h"

#include "mlx.h"

#include <math.h>
#include <stdio.h>

void	ui_draw_projection(t_cub *cub)
{
	t_ray		ray;
	t_shape		shape;
	float		height;
	float		offset;
	int			i;
	uint32_t	color;

	i = -WIN_WIDTH / 2;
	while (i < WIN_WIDTH / 2)
	{
		ray_init(&ray, &cub->player, cub->player.yaw + ((float)i / WIN_WIDTH));
		if (ray_cast(&ray, RENDER_DISTANCE))
		{
			ray.distance *= cos(cub->player.yaw - ray.angle);
			height = WIN_HEIGHT / ray.distance;
			offset = (WIN_HEIGHT / 2.0f) - height / 2.0f;
			shape.line = (struct s_line){
				i + (WIN_WIDTH / 2), i + (WIN_WIDTH / 2),
				offset, (height + offset),
			};
			switch (ray.hit_face)
			{
				case NORTH: color = 0x444444; break;
				case SOUTH: color = 0xAAAA00; break;
				case EAST:  color = 0xAA00AA; break;
				case WEST:  color = 0x00AAAA; break;
				default:    color = 0xFFFFFF;
			}
			canvas_draw_shape(&cub->screen, draw_line, &shape, (0xFF << 24) | color);
		}
		++i;
	}
}
