/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:03:48 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/16 21:15:58 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "utils.h"

#include <math.h>

static void	_draw_line_dda(t_canvas *canvas, struct s_line const *line,
	uint32_t color)
{
	float	x;
	float	y;
	float	dx;
	float	dy;
	float	step;
	int		i;

	dx = (line->x2 - line->x1);
	dy = (line->y2 - line->y1);
	if (fabs(dx) >= fabs(dy))
		step = fabs(dx);
	else
		step = fabs(dy);
	dx /= step;
	dy /= step;
	x = line->x1;
	y = line->y1;
	i = 1;
	while (i <= step)
	{
		canvas_setpx(canvas, x, y, color);
		x += dx;
		y += dy;
		++i;
	}
}

void	draw_line(t_canvas *canvas, t_shape const *shape, uint32_t color)
{
	struct s_line	line = shape->line;

	_draw_line_dda(canvas, &line, color);
}
