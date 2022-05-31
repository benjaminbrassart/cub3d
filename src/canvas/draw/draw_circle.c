/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 20:37:55 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/16 18:25:15 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

#include <math.h>

void	draw_circle(t_canvas *canvas, t_shape const *shape, uint32_t color)
{
	struct s_circle const	*circle = &shape->circle;
	float					angle;
	float					x;
	float					y;

	angle = 0.0f;
	while (angle < 360.0f)
	{
		x = circle->radius * (cosf(angle * M_PI / 180.0f));
		y = circle->radius * (sinf(angle * M_PI / 180.0f));
		canvas_setpx(canvas, circle->x + x, circle->y + y, color);
		angle += 0.1f;
	}
}
