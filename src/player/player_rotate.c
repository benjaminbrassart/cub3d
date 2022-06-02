/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:25:54 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/02 09:08:28 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

#include "cub.h"

#include <math.h>

void	player_rotate(t_cub *cub, int yaw)
{
	if (yaw != 0)
	{
		cub->player.yaw += (yaw * CAMERA_SPEED);
		if (cub->player.yaw < 0)
			cub->player.yaw += M_PI * 2;
		if (cub->player.yaw > M_PI * 2)
			cub->player.yaw -= M_PI * 2;
	}
}
