/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:12:14 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/12 15:14:10 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

#include "cub.h"
#include "cuberr.h"
#include "def.h"
#include "mlx_handle.h"

#include "mlx.h"

#include <stddef.h>
#include <X11/X.h>

static int	_init_display(t_cub *cub);
static int	_init_window(t_cub *cub);
static void	_setup_handlers(t_cub *cub);

int	cub_init(t_cub *cub)
{
	int	res;

	res = (_init_display(cub) && _init_window(cub));
	if (res != RES_FAILURE)
		_setup_handlers(cub);
	return (res);
}

static int	_init_display(t_cub *cub)
{
	cub->mlx = mlx_init();
	if (cub->mlx == NULL)
	{
		print_error("minilibx", "Failed to initialize display");
		return (RES_FAILURE);
	}
	return (RES_SUCCESS);
}

static int	_init_window(t_cub *cub)
{
	cub->win = mlx_new_window(cub->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (cub->win == NULL)
	{
		print_error("minilibx", "Failed to initialize window");
		return (RES_FAILURE);
	}
	return (RES_SUCCESS);
}

static void	_setup_handlers(t_cub *cub)
{
	mlx_hook(cub->win, DestroyNotify, NoEventMask, destroy_handle, cub);
}
