/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:12:56 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/20 15:09:50 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# define COLOR_CEILING	0
# define COLOR_FLOOR	1

# include "player.h"
# include "ray.h"

# include <stdbool.h>
# include <stdint.h>

typedef struct s_cub	t_cub;
typedef struct s_canvas	t_canvas;

union u_file
{
	char const	*path;
	int			fd;
};

struct s_canvas
{
	void			*img;
	char			*raw;
	int				line_len;
	int				bpp;
	int				endian;
	unsigned int	height;
	unsigned int	width;
	bool			updated;
};

struct s_cub
{
	void			*mlx;
	void			*win;
	t_canvas		screen;
	union u_file	map_file;
	t_player		player;
	t_ray			*rays;
	uint32_t		colors[2];
};

#endif
