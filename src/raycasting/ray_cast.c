/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:18:31 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/23 04:14:12 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "removeme.h" //! remove

#include "ray.h"

#include "ft.h"

#include <math.h>

//? https://github.com/mrouabeh/42-Cub3D/blob/master/inc/structures.h
//? https://github.com/mrouabeh/42-Cub3D/blob/master/src/engine/raycasting.c
//? https://github.com/mrouabeh/42-Cub3D/blob/master/src/engine/digital_differential_analyser.c

//! FIXME have a length array for each line in map to avoid
//! calculation of ft_strlen(map[y])
static bool	_check_found(t_ray const *ray)
{
	return (ray->check.y >= 0 && ray->check.y < MAP_HEIGHT
		&& ray->check.x >= 0
		&& (unsigned int)ray->check.x < ft_strlen(g_map[ray->check.y])
		&& g_map[ray->check.y][ray->check.x] == '1');
}

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

bool	ray_cast(t_ray *ray, float max_distance)
{
	bool	tile_found;
	float	dist;

	dist = 0.0f;
	tile_found = false;
	while (!tile_found && dist < max_distance)
	{
		dist = _compute_new_distance(ray);
		tile_found = _check_found(ray);
	}
	if (tile_found)
	{
		ray->result.x = ray->start.x + ray->dir.x * dist;
		ray->result.y = ray->start.y + ray->dir.y * dist;
		ray->distance = dist;
	}
	return (tile_found);
}
