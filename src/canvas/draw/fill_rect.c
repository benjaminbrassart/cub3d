/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:16:46 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/16 18:19:15 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

void	fill_rect(t_canvas *canvas, t_shape const *shape, uint32_t color)
{
	struct s_rect const	*rect = &shape->rectangle;
	int					x;
	int					y;

	y = rect->y1;
	while (y <= rect->y2)
	{
		x = rect->x1;
		while (x <= rect->x2)
		{
			canvas_setpx(canvas, x, y, color);
			++x;
		}
		++y;
	}
}
