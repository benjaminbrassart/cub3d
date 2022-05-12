/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:11:05 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/12 18:15:03 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "mlx_handle.h"

#include "mlx.h"

#include <math.h>

int	loop_handle(t_cub *cub)
{
	mlx_pixel_put(cub->mlx, cub->win, roundf(cub->player.x),
		roundf(cub->player.y), 0xFFFF0000); // TODO
	return (0);
}
