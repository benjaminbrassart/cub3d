/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:13:58 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/03 08:07:18 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "cuberr.h"
#include "def.h"
#include "lifecycle.h"

#include "ft.h"
#include "mlx.h"

#include <math.h>

int	cub_run(t_cub *cub)
{
	cub->player.x += 0.5;
	cub->player.y += 0.5;
	mlx_loop(cub->mlx);
	return (RES_SUCCESS);
}
