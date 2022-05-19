/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:37:07 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/19 13:01:05 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "removeme.h"

#include "canvas.h"
#include "cub.h"
#include "lifecycle.h"
#include "ray.h"
#include "ui.h"
#include "utils.h"

#include <math.h>
#include <stddef.h>

void	cub_update(t_cub *cub)
{
	canvas_clear(&cub->screen);
	ui_draw_background(cub);
	ui_draw_projection(cub);
	ui_draw_minimap(cub);
	ui_draw_info(cub);
}
