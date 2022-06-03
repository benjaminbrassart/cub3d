/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:36:51 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/03 10:26:54 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

#include "cub.h"
#include "cuberr.h"
#include "def.h"
#include "lifecycle.h"
#include "mlx_handle.h"

#include "ft.h"
#include "mlx.h"

#include <stddef.h>
#include <X11/X.h>

int	cub_init_window(t_cub *cub)
{
	cub->win = mlx_new_window(cub->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (cub->win == NULL)
	{
		print_error("minilibx", ERROR_INIT_WINDOW);
		return (RES_FAILURE);
	}
	mlx_loop_hook(cub->mlx, loop_handle, cub);
	mlx_hook(cub->win, DestroyNotify, NoEventMask, destroy_handle, cub);
	mlx_hook(cub->win, KeyPress, KeyPressMask, key_press_handle, cub);
	mlx_hook(cub->win, KeyRelease, KeyReleaseMask, key_release_handle, cub);
	return (RES_SUCCESS);
}
