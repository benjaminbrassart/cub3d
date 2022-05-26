/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:11:05 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/26 13:28:59 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "removeme.h" //! remove

#include "config.h"

#include "canvas.h"
#include "cub.h"
#include "input.h"
#include "lifecycle.h"
#include "mlx_handle.h"
#include "ray.h"
#include "utils.h"

#include "ft.h"
#include "mlx.h"

#include <stddef.h>
#include <math.h>

int	loop_handle(t_cub *cub)
{
	size_t				n;
	struct s_factors	factors;

	ft_memset(&factors, 0, sizeof (factors));
	n = 0;
	while (n < (sizeof (g_inputs) / sizeof (*g_inputs)))
	{
		if (cub->player.input_mask & g_inputs[n].action.mask)
		{
			if (g_inputs[n].action.mask & INPUT_EXIT)
				return (destroy_handle(cub));
			factors_add(&g_inputs[n].action.factors, &factors);
		}
		++n;
	}
	player_rotate(&cub->player, factors.yaw, factors.pitch);
	player_move(&cub->player, factors.x, factors.y);
	cub_update(cub);
	return (0);
}
