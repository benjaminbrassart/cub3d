/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:12:14 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/12 14:20:43 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

#include "cub.h"
#include "cuberr.h"
#include "mlx.h"

#include <stddef.h>

static int	_init_display(t_cub *cub);
static int	_init_window(t_cub *cub);

int	cub_init(t_cub *cub)
{
	return (_init_display(cub) && _init_window(cub));
}

static int	_init_display(t_cub *cub)
{
	cub->mlx = mlx_init();
	if (cub->mlx == NULL)
	{
		print_error("minilibx", "Failed to initialize display");
		return (0);
	}
	return (1);
}

static int	_init_window(t_cub *cub)
{
	cub->win = mlx_new_window(cub->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (cub->win == NULL)
	{
		print_error("minilibx", "Failed to initialize window");
		return (0);
	}
	return (1);
}
