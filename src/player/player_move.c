/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:27:37 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/03 14:31:51 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "cub.h"

#include <math.h>

void	player_move(t_cub *cub, float angle)
{
	float const	mx = MOVEMENT_SPEED * cos(cub->player.yaw + angle);
	float const	my = MOVEMENT_SPEED * sin(cub->player.yaw + angle);
	t_ray		ray;

	ray_init(&ray, &cub->player, cub->player.yaw + angle);
	if (!ray_cast(cub, &ray, 0.1) || ray.distance > 0.1)
	{
		cub->player.x += mx;
		cub->player.y += my;
	}
}
