/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_draw_projection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:15:35 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/01 04:16:29 by bbrassar         ###   ########.fr       */
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
	float const	*axis;
	int			res;

	if (ray->hit_face == NORTH || ray->hit_face == SOUTH)
		axis = &ray->result.x;
	else
		axis = &ray->result.y;
	res = (int)(ft_modf(*axis, 1.0f) * canvas->width);
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
	float			offset;
	float			height;
	float			n;

	height = WIN_HEIGHT / ray->distance;
	offset = ((float)WIN_HEIGHT - height) / 2;
	n = 0;
	if (offset < 0.0f)
	{
		n = -offset;
		height += offset;
	}
	while (n < height)
	{
		canvas_setpx(&cub->screen, i + (WIN_WIDTH / 2), offset + n,
			canvas_getpx(canvas, _get_line(canvas, ray),
				_get_column(canvas, ray, n)));
		n += 0.9;
	}
}

void	ui_draw_projection(t_cub *cub)
{
	t_ray	ray;
	int		i;
	bool	cast;

	i = -WIN_WIDTH / 2;
	while (i < WIN_WIDTH / 2)
	{
		ray_init(&ray, &cub->player, cub->player.yaw + (1.0f * i / WIN_WIDTH));
		cast = ray_cast(cub, &ray, RENDER_DISTANCE);
		if (cast)
		{
			ray.distance *= cos(cub->player.yaw - ray.angle);
			_draw_textured(cub, &ray, i);
		}
		++i;
	}
}
