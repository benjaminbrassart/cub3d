/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_draw_background.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:15:41 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/19 12:19:30 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

#include "canvas.h"
#include "ui.h"

void	ui_draw_background(t_cub *cub)
{
	t_shape	shape;

	shape.rectangle = (struct s_rect){
		0, WIN_WIDTH,
		0, WIN_HEIGHT / 2,
	};
	canvas_draw_shape(&cub->screen, fill_rect, &shape, 0xAADDFF); // TODO
	shape.rectangle = (struct s_rect){
		0, WIN_WIDTH,
		WIN_HEIGHT / 2, WIN_HEIGHT,
	};
	canvas_draw_shape(&cub->screen, fill_rect, &shape, 0xAAFFAA); // TODO
}
