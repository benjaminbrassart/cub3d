/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:02:20 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/17 18:33:07 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "ray.h"

#include "ft.h"

#include <math.h>

static void	_compute_step(t_ray *ray)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->length.x = (ray->start.x - ray->check.x) * ray->unit.x;
	}
	else
	{
		ray->step.x = 1;
		ray->length.x = ((ray->check.x + 1) - ray->start.x) * ray->unit.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->length.y = (ray->start.y - ray->check.y) * ray->unit.y;
	}
	else
	{
		ray->step.y = 1;
		ray->length.y = ((ray->check.y + 1) - ray->start.y) * ray->unit.y;
	}
}

void	ray_init(t_ray *ray, t_player const *player, float yaw)
{
	ray->angle = yaw;
	ray->start.x = player->x;
	ray->start.y = player->y;
	ray->dir.x = cos(yaw);
	ray->dir.y = sin(yaw);
	ray->unit.x = sqrt(1 + pow(ray->dir.y / ray->dir.x, 2));
	ray->unit.y = sqrt(1 + pow(ray->dir.x / ray->dir.y, 2));
	ray->check.x = (int)ray->start.x;
	ray->check.y = (int)ray->start.y;
	_compute_step(ray);
}
