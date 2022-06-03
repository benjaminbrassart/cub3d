/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:03:48 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/18 13:48:59 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "utils.h"

#include <math.h>

static void	_draw_line_dda(t_canvas *canvas, struct s_line const *line,
	uint32_t color)
{
	float	pos[2];
	float	delta[2];
	float	step;
	int		i;

	delta[0] = (line->x2 - line->x1);
	delta[1] = (line->y2 - line->y1);
	if (fabs(delta[0]) >= fabs(delta[1]))
		step = fabs(delta[0]);
	else
		step = fabs(delta[1]);
	delta[0] /= step;
	delta[1] /= step;
	pos[0] = line->x1;
	pos[1] = line->y1;
	i = 1;
	while (i <= step)
	{
		canvas_setpx(canvas, pos[0], pos[1], color);
		pos[0] += delta[0];
		pos[1] += delta[1];
		++i;
	}
}

void	draw_line(t_canvas *canvas, t_shape const *shape, uint32_t color)
{
	struct s_line const	line = shape->line;

	_draw_line_dda(canvas, &line, color);
}
