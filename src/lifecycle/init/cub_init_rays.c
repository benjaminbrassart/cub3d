/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:37:46 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/18 13:46:53 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

#include "cub.h"
#include "def.h"
#include "lifecycle.h"

#include "ft.h"
#include "mlx.h"

#include <stddef.h>
#include <stdlib.h>

int	cub_init_rays(t_cub *cub)
{
	cub->rays = malloc(WIN_WIDTH * sizeof (*cub->rays));
	if (cub->rays != NULL)
		return (RES_SUCCESS);
	return (RES_FAILURE);
}
