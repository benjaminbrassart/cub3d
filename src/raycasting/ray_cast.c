/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:18:31 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/01 04:18:23 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

#include "def.h"
#include "ray.h"

#include "ft.h"

#include <math.h>

static float	_compute_new_distance(t_ray *ray)
{
	float	dist;

	if (ray->length.x < ray->length.y)
	{
		ray->check.x += ray->step.x;
		dist = ray->length.x;
		ray->length.x += ray->unit.x;
		if (ray->step.x == -1)
			ray->hit_face = WEST;
		else
			ray->hit_face = EAST;
	}
	else
	{
		ray->check.y += ray->step.y;
		dist = ray->length.y;
		ray->length.y += ray->unit.y;
		if (ray->step.y == -1)
			ray->hit_face = NORTH;
		else
			ray->hit_face = SOUTH;
	}
	return (dist);
}

bool	ray_cast(t_cub const *cub, t_ray *ray, float max_distance)
{
	bool	tile_found;
	float	dist;

	dist = 0.0f;
	tile_found = false;
	while (!tile_found && dist < max_distance)
	{
		dist = _compute_new_distance(ray);
		tile_found = (map_gettile(cub, ray->check.x, ray->check.y) == '1');
	}
	if (tile_found)
	{
		ray->result.x = ray->start.x + ray->dir.x * dist;
		ray->result.y = ray->start.y + ray->dir.y * dist;
		ray->distance = dist;
	}
	return (tile_found);
}
