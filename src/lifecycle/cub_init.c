/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:12:14 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/15 17:10:27 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

#include "canvas.h"
#include "cub.h"
#include "cuberr.h"
#include "def.h"
#include "mlx_handle.h"

#include "ft.h"
#include "mlx.h"

#include <stddef.h>
#include <X11/X.h>

static int	_init_display(t_cub *cub);
static int	_init_window(t_cub *cub);
static int	_init_screen(t_cub *cub);
static void	_setup_handlers(t_cub *cub);

int	cub_init(t_cub *cub)
{
	int	res;

	ft_memset(&cub->player, 0, sizeof (cub->player));
	res = (_init_display(cub) && _init_window(cub) && _init_screen(cub));
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
	mlx_do_key_autorepeatoff(cub->mlx);
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

static int	_init_screen(t_cub *cub)
{
	cub->screen.img = mlx_new_image(cub->mlx, WIN_HEIGHT, WIN_WIDTH);
	if (cub->screen.img == NULL)
	{
		print_error("minilibx", "Failed to initialize canvas");
		return (0);
	}
	cub->screen.raw = mlx_get_data_addr(cub->screen.img, &cub->screen.bpp,
			&cub->screen.line_len, &cub->screen.endian);
	if (cub->screen.raw == NULL)
	{
		print_error("minilibx", "Failed to initialize canvas");
		return (0);
	}
	cub->screen.height = WIN_HEIGHT;
	cub->screen.width = WIN_WIDTH;
	canvas_clear(&cub->screen);
	canvas_unsafe_setpx(&cub->screen, 300, 300, 0xFFFF0000);
	return (1);
}

static void	_setup_handlers(t_cub *cub)
{
	mlx_loop_hook(cub->mlx, loop_handle, cub);
	mlx_hook(cub->win, DestroyNotify, NoEventMask, destroy_handle, cub);
	mlx_hook(cub->win, KeyPress, KeyPressMask, key_press_handle, cub);
	mlx_hook(cub->win, KeyRelease, KeyReleaseMask, key_release_handle, cub);
}
