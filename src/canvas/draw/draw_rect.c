/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 20:42:38 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/15 20:45:56 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

void	draw_rect(t_canvas *canvas, t_shape *shape, uint32_t color)
{
	struct s_rect const	*rect = &shape->rectangle;
	int					i;

	i = rect->y1;
	while (i <= rect->y2)
	{
		canvas_setpx(canvas, rect->x1, i, color);
		canvas_setpx(canvas, rect->x2, i, color);
	}
	i = rect->x1;
	while (i <= rect->x2)
	{
		canvas_setpx(canvas, i, rect->y1, color);
		canvas_setpx(canvas, i, rect->y2, color);
	}
}
