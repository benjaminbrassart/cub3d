/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_draw_projection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:15:35 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/23 17:34:13 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

#include "canvas.h"
#include "ray.h"
#include "ui.h"

#include "mlx.h"

#include <math.h>
#include <stdio.h>

static int	_get_line(t_canvas const *canvas, t_ray const *ray)
{
	float	axis;
	int		res;

	if (ray->hit_face == NORTH || ray->hit_face == SOUTH)
		axis = ray->result.x;
	else
		axis = ray->result.y;
	res = (int)(ft_modf(axis, 1.0f) * canvas->width);
	return (res);
}

static int	_get_column(t_canvas const *canvas, t_ray const *ray, float n)
{
	float const	height = WIN_HEIGHT / ray->distance;

	return ((n / height) * canvas->height);
}

static void	_draw_textured(t_cub *cub, t_ray *ray, int i)
{
	t_canvas const	*canvas = &cub->textures[ray->hit_face];
	float const		height = WIN_HEIGHT / ray->distance;
	float const		offset = ((1 - cub->player.pitch / M_PI) * WIN_HEIGHT)
		- height / 2;
	float			n;

	n = 0;
	while (n < height)
	{
		canvas_setpx(&cub->screen, i + (WIN_WIDTH / 2), offset + n,
			canvas_getpx(canvas, _get_line(canvas, ray),
				_get_column(canvas, ray, n)));
		++n;
	}
	// shape.line = (struct s_line){
	// 	i + (WIN_WIDTH / 2), i + (WIN_WIDTH / 2),
	// 	offset, (height + offset),
	// };
}

void	ui_draw_projection(t_cub *cub)
{
	t_ray		ray;
	int			i;

	i = -WIN_WIDTH / 2;
	while (i < WIN_WIDTH / 2)
	{
		ray_init(&ray, &cub->player, cub->player.yaw + (1.0f * i / WIN_WIDTH));
		if (ray_cast(&ray, RENDER_DISTANCE))
		{
			ray.distance *= cos(cub->player.yaw - ray.angle);
			_draw_textured(cub, &ray, i);
		}
		++i;
	}
}
