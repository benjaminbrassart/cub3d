/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:25:43 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/01 08:12:24 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "lifecycle.h"

#include "mlx.h"

#include <stdlib.h>

static void	_destroy_textures(t_cub *cub);
static void	_destroy_map(t_cub *cub);

void	cub_destroy(t_cub *cub)
{
	if (cub->mlx != NULL)
	{
		mlx_do_key_autorepeaton(cub->mlx);
		_destroy_textures(cub);
		canvas_destroy(cub->mlx, &cub->screen);
		if (cub->win != NULL)
			mlx_destroy_window(cub->mlx, cub->win);
		mlx_destroy_display(cub->mlx);
		free(cub->mlx);
	}
	_destroy_map(cub);
}

static void	_destroy_textures(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (cub->textures[i].img != NULL)
			mlx_destroy_image(cub->mlx, cub->textures[i].img);
		++i;
	}
}

static void	_destroy_map(t_cub *cub)
{
	size_t	n;

	free(cub->map_lengths);
	if (cub->map == NULL)
		return ;
	n = 0;
	while (cub->map[n])
	{
		free(cub->map[n]);
		++n;
	}
	free(cub->map);
}
