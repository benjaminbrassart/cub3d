/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:36:12 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/18 13:41:03 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

#include "canvas.h"
#include "cub.h"
#include "cuberr.h"
#include "def.h"
#include "lifecycle.h"

#include "ft.h"
#include "mlx.h"

#include <stddef.h>

int	cub_init_screen(t_cub *cub)
{
	cub->screen.img = mlx_new_image(cub->mlx, WIN_WIDTH, WIN_HEIGHT);
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
	return (1);
}
