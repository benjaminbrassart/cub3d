/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:18:31 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/16 21:28:03 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "removeme.h" //! remove

#include "ray.h"

#include "ft.h"

static bool	_check_found(t_ray const *ray)
{
	return (ray->check.y >= 0 && ray->check.y < MAP_HEIGHT
		&& ray->check.x >= 0
		&& (unsigned int)ray->check.x < ft_strlen(g_map[ray->check.y])
		&& g_map[ray->check.y][ray->check.x] == '1');
}

bool	ray_cast(t_ray *ray, float *distance, float *x, float *y)
{
	bool	tile_found;
	float	dist;

	dist = 0.0f;
	tile_found = false;
	while (!tile_found && dist < RENDER_DISTANCE)
	{
		if (ray->length.x < ray->length.y)
		{
			ray->check.x += ray->step.x;
			dist = ray->length.x;
			ray->length.x += ray->unit.x;
		}
		else
		{
			ray->check.y += ray->step.y;
			dist = ray->length.y;
			ray->length.y += ray->unit.y;
		}
		tile_found = _check_found(ray);
	}
	if (tile_found)
	{
		*x = ray->start.x + ray->dir.x * dist;
		*y = ray->start.y + ray->dir.y * dist;
		*distance = dist;
	}
	return (tile_found);
}
