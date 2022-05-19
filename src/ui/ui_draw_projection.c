/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_draw_projection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:15:35 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/19 12:20:31 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

#include "canvas.h"
#include "ray.h"
#include "ui.h"

#include <math.h>

void	ui_draw_projection(t_cub *cub)
{
	t_ray	ray;
	float	distance;
	t_shape	shape;
	float	height;
	float	offset;

	for (float i = -WIN_WIDTH / 2; i <= WIN_WIDTH / 2; ++i)
	{
		ray_init(&ray, &cub->player, cub->player.yaw + (i / WIN_WIDTH));
		if (ray_cast(&ray, &distance, NULL, NULL))
		{
			distance *= cos(cub->player.yaw - ray.angle);
			height = WIN_HEIGHT / distance;
			offset = (WIN_HEIGHT / 2.0f) - height / 2.0f;
			shape.line = (struct s_line){
				i + (WIN_WIDTH / 2), i + (WIN_WIDTH / 2),
				offset, (height + offset),
			};
			canvas_draw_shape(&cub->screen, draw_line, &shape, 0xFFFF0000);
		}
	}
}
