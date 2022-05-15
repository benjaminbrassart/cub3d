/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:38:30 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/15 17:13:23 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

# include "cub.h"

# include <stdint.h>

void	canvas_setpx(t_canvas *canvas, int x, int y, uint32_t color);
void	canvas_unsafe_setpx(t_canvas *canvas, unsigned int x, unsigned int y,
			uint32_t color);
void	canvas_clear(t_canvas *canvas);
void	canvas_draw(t_cub *cub, t_canvas *canvas, int x, int y);
void	canvas_destroy(void *mlx, t_canvas *canvas);

#endif
