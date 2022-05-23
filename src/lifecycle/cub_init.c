/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:12:14 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/23 15:41:41 by bbrassar         ###   ########.fr       */
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
#include <X11/X.h>

static void	_setup_handlers(t_cub *cub);

int	cub_init(t_cub *cub)
{
	int	res;

	ft_memset(&cub->player, 0, sizeof (cub->player));
	cub->player.pitch = M_PI_2;
	res = (cub_init_display(cub)
			&& cub_init_window(cub)
			&& cub_init_screen(cub)
			&& cub_init_rays(cub));
	if (res != RES_FAILURE)
		_setup_handlers(cub);
	return (res);
}

static void	_setup_handlers(t_cub *cub)
{
	mlx_loop_hook(cub->mlx, loop_handle, cub);
	mlx_hook(cub->win, DestroyNotify, NoEventMask, destroy_handle, cub);
	mlx_hook(cub->win, KeyPress, KeyPressMask, key_press_handle, cub);
	mlx_hook(cub->win, KeyRelease, KeyReleaseMask, key_release_handle, cub);
}
