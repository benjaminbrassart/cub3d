/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_getpx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:45:29 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/23 16:54:10 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

uint32_t	canvas_getpx(t_canvas const *canvas, float x, float y)
{
	if (x < 0 || x >= canvas->width || y < 0 || y >= canvas->height)
		return (0x00000000);
	return (canvas_unsafe_getpx(canvas, (int)x, (int)y));
}

uint32_t	canvas_unsafe_getpx(t_canvas const *canvas, int x, int y)
{
	uint32_t const	*addr = (uint32_t *)canvas->raw;

	return (addr[y * canvas->width + x]);
}
