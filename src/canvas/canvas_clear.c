/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:44:23 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/15 17:12:43 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

void	canvas_clear(t_canvas *canvas)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < canvas->height)
	{
		x = 0;
		while (x < canvas->width)
		{
			canvas_unsafe_setpx(canvas, x, y, 0xFF888888);
			++x;
		}
		++y;
	}
}
