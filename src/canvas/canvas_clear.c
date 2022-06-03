/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:44:23 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/17 16:45:05 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

#include "ft.h"

void	canvas_clear(t_canvas *canvas)
{
	ft_memset(canvas->raw, 0, canvas->height * canvas->width
		* (canvas->bpp / 8));
}
