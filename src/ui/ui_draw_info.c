/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_draw_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:58:29 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/19 12:59:25 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "ui.h"

#include <math.h>
#include <stdio.h>

void	ui_draw_info(t_cub *cub)
{
	char	text[1024];

	snprintf(text, sizeof (text), "x: %.2f y: %.2f", cub->player.x,
		cub->player.y);
	mlx_string_put(cub->mlx, cub->win, 10, 345, 0xFFFFFFFF, text);
	snprintf(text, sizeof (text), "yaw: %.2f",
		cub->player.yaw * (180 / M_PI) - 180);
	mlx_string_put(cub->mlx, cub->win, 10, 360, 0xFFFFFFFF, text);
}
