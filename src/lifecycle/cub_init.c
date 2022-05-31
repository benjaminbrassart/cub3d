/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:12:14 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/01 00:17:04 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

#include "canvas.h"
#include "cub.h"
#include "cuberr.h"
#include "def.h"
#include "lifecycle.h"
#include "mlx_handle.h"

#include "ft.h"
#include "mlx.h"

#include <math.h>
#include <stddef.h>

int	cub_init(t_cub *cub)
{
	ft_memset(&cub->player, 0, sizeof (cub->player));
	cub->player.pitch = M_PI_2;
	return (cub_init_display(cub) && cub_init_screen(cub));
}
