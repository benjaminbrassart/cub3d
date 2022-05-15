/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_draw_shape.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 20:03:36 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/15 20:42:34 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

#include <stddef.h>

static void	_draw_rect(t_canvas *canvas, t_shape *shape, uint32_t color)
{

}

void	canvas_draw_shape(t_canvas *canvas, t_shape_draw_fn *fn, t_shape *shape,
	uint32_t color)
{
	if (canvas != NULL && fn != NULL && shape != NULL)
		fn(canvas, shape, color);
}
