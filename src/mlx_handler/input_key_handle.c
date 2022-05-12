/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_key_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:06:02 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/12 17:47:06 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "mlx_handle.h"

#include "mlx.h"

#include <X11/keysym.h>

static void	_move_player_x(t_cub *cub, int factor);
static void	_move_player_y(t_cub *cub, int factor);
static void	_move_player_yaw(t_cub *cub, int factor);

int	input_key_handle(int key, t_cub *cub)
{
	int	factor_x;
	int	factor_y;
	int	factor_yaw;

	factor_x = 0;
	factor_y = 0;
	factor_yaw = 0;
	if (key == XK_Escape)
		return (destroy_handle(cub));
	if (key == XK_W)
		--factor_y;
	if (key == XK_S)
		++factor_y;
	if (key == XK_D)
		++factor_x;
	if (key == XK_A)
		--factor_x;
	if (key == XK_Left)
		--factor_yaw;
	if (key == XK_Right)
		++factor_yaw;
	_move_player_x(cub, factor_x);
	_move_player_y(cub, factor_y);
	_move_player_yaw(cub, factor_yaw);
	return (0);
}

static void	_move_player_x(t_cub *cub, int factor)
{
	(void)cub;
	(void)factor;
}

static void	_move_player_y(t_cub *cub, int factor)
{
	(void)cub;
	(void)factor;
}

static void	_move_player_yaw(t_cub *cub, int factor)
{
	(void)cub;
	(void)factor;
}
