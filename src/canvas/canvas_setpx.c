/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_setpx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:38:23 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/15 17:13:28 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

void	canvas_setpx(t_canvas *canvas, int x, int y, uint32_t color)
{
	if (x < 0 || y < 0 || (unsigned int)x > canvas->width
		|| (unsigned int)y > canvas->height)
		return ;
	canvas_unsafe_setpx(canvas, (unsigned int)x, (unsigned int)y, color);
}

void	canvas_unsafe_setpx(t_canvas *canvas, unsigned int x, unsigned int y,
	uint32_t color)
{
	unsigned int	*dst;

	dst = (unsigned int *)(canvas->raw
			+ (y * canvas->line_len + x * (canvas->bpp / 8)));
	if (*dst != color)
	{
		*dst = color;
		canvas->updated = 1;
	}
}
