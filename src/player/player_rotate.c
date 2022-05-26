/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:25:54 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/26 13:28:53 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

#include "player.h"

#include <math.h>

void	player_rotate(t_player *player, int yaw, int pitch)
{
	if (yaw != 0)
		player->yaw = ft_modf(player->yaw + (yaw * CAMERA_SPEED), M_PI * 2);
	if (pitch != 0)
		player->pitch = player->pitch + (pitch * CAMERA_SPEED);
	if (player->pitch > M_PI)
		player->pitch = M_PI;
	if (player->pitch < 0)
		player->pitch = 0;
}
