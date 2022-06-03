/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:58:17 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/19 12:36:05 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_H
# define UI_H

# include "cub.h"
# include <stddef.h>

struct s_tile_color
{
	char const	*charset;
	uint32_t	color;
};

static struct s_tile_color const	g_tile_colors[] = {
{"0", 0xFF00FF},
{"1", 0x888888},
{"NSEW", 0xFFFFFF},
{NULL, 0x000000},
};

struct s_tile_color const	*get_tile_color(char tile);

void						ui_draw_minimap(t_cub *cub);
void						ui_draw_background(t_cub *cub);
void						ui_draw_projection(t_cub *cub);
void						ui_draw_info(t_cub *cub);

#endif
