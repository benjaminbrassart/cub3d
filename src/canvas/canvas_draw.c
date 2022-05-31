/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:51:41 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/15 16:53:44 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

#include "mlx.h"

void	canvas_draw(t_cub *cub, t_canvas *canvas, int x, int y)
{
	mlx_put_image_to_window(cub->mlx, cub->win, canvas->img, x, y);
}
