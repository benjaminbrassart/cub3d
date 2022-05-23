/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:38:30 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/23 04:40:09 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

# include "cub.h"

# include <stdint.h>

typedef union u_shape	t_shape;
typedef void			(t_shape_draw_fn)(t_canvas *, t_shape const *,
							uint32_t);

struct s_rect
{
	int	x1;
	int	x2;
	int	y1;
	int	y2;
};

struct s_circle
{
	int	x;
	int	y;
	int	radius;
};

struct s_line
{
	int	x1;
	int	x2;
	int	y1;
	int	y2;
};

union u_shape
{
	struct s_rect	rectangle;
	struct s_circle	circle;
	struct s_line	line;
};

t_canvas	*canvas_load(t_cub const *cub, char const *filename, t_canvas *out);
void		canvas_destroy(void *mlx, t_canvas *canvas);

void		canvas_setpx(t_canvas *canvas, int x, int y, uint32_t color);
void		canvas_unsafe_setpx(t_canvas *canvas, unsigned int x,
				unsigned int y, uint32_t color);
void		canvas_clear(t_canvas *canvas);
void		canvas_draw(t_cub *cub, t_canvas *canvas, int x, int y);
void		canvas_draw_shape(t_canvas *canvas, t_shape_draw_fn *fn,
				t_shape const *shape, uint32_t color);

void		draw_rect(t_canvas *canvas, t_shape const *shape, uint32_t color);
void		draw_circle(t_canvas *canvas, t_shape const *shape, uint32_t color);
void		draw_line(t_canvas *canvas, t_shape const *shape, uint32_t color);
void		fill_rect(t_canvas *canvas, t_shape const *shape, uint32_t color);
void		fill_circle(t_canvas *canvas, t_shape const *shape, uint32_t color);

#endif
