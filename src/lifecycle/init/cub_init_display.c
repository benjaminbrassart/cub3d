/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:35:32 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/18 13:41:33 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "cuberr.h"
#include "def.h"
#include "lifecycle.h"

#include "ft.h"
#include "mlx.h"

#include <stddef.h>

int	cub_init_display(t_cub *cub)
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
