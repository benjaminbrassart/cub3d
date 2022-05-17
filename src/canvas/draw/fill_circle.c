/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:16:33 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/17 16:44:52 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

#include <math.h>

void	fill_circle(t_canvas *canvas, t_shape const *shape, uint32_t color)
{
	struct s_circle const	*circle = &shape->circle;
	int						x;
	int						y;

	y = circle->y - circle->radius;
	while (y <= circle->y + circle->radius)
	{
		x = circle->x - circle->radius;
		while (x <= circle->x + circle->radius)
		{
			if (pow(x - circle->x, 2) + pow(y - circle->y, 2)
				< pow(circle->radius, 2))
				canvas_setpx(canvas, x, y, color);
			++x;
		}
		++y;
	}
}
