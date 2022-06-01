/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:12:56 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/01 04:10:25 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "def.h"
# include "player.h"
# include "ray.h"

# include <stdbool.h>
# include <stdint.h>
# include <stddef.h>

typedef struct s_cub	t_cub;
typedef struct s_canvas	t_canvas;

struct s_canvas
{
	void			*img;
	char			*raw;
	int				line_len;
	int				bpp;
	int				endian;
	unsigned int	height;
	unsigned int	width;
};

struct s_cub
{
	void			*mlx;
	void			*win;
	t_canvas		screen;
	char const		*map_file;
	t_player		player;
	uint32_t		colors[2];
	t_canvas		textures[4];
	char			**map;
	size_t			*map_lengths;
	size_t			map_height;
};

char	map_gettile(t_cub const *cub, int x, int y);

#endif
