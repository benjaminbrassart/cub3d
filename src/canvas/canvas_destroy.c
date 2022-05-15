/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:54:55 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/15 16:55:50 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

#include "mlx.h"

void	canvas_destroy(void *mlx, t_canvas *canvas)
{
	mlx_destroy_image(mlx, canvas->img);
}
