/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:25:54 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/01 09:20:38 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

#include "player.h"

#include <math.h>

void	player_rotate(t_player *player, int yaw)
{
	if (yaw != 0)
		player->yaw = ft_modf(player->yaw + (yaw * CAMERA_SPEED), M_PI * 2);
}
