/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:12:56 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/02 15:24:39 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "def.h"
# include "ray.h"

# include <stdbool.h>
# include <stdint.h>
# include <stddef.h>
# include <X11/keysym.h>

typedef struct s_cub	t_cub;
typedef struct s_canvas	t_canvas;
typedef struct s_player	t_player;

# define INPUT_INIT			INPUT_INIT
# define INPUT_EXIT			INPUT_EXIT
# define INPUT_UP			INPUT_UP
# define INPUT_DOWN			INPUT_DOWN
# define INPUT_LEFT			INPUT_LEFT
# define INPUT_RIGHT		INPUT_RIGHT
# define INPUT_CAM_LEFT		INPUT_CAM_LEFT
# define INPUT_CAM_RIGHT	INPUT_CAM_RIGHT

# include "cub.h"
# include "utils.h"

# include <math.h>

# include <stddef.h>

enum e_input_mask
{
	INPUT_INIT		= (0),
	INPUT_EXIT		= (1 << 0),
	INPUT_UP		= (1 << 1),
	INPUT_DOWN		= (1 << 2),
	INPUT_LEFT		= (1 << 3),
	INPUT_RIGHT		= (1 << 4),
	INPUT_CAM_LEFT	= (1 << 5),
	INPUT_CAM_RIGHT	= (1 << 6),
	INPUT_CAM_UP	= (1 << 7),
	INPUT_CAM_DOWN	= (1 << 8),
};

struct s_input
{
	int	key;
	struct s_action
	{
		enum e_input_mask	mask;
		void				(*move_fn)(t_cub *, float);
		float				offset;
	}	action;
};

struct s_player
{
	float				x;
	float				y;
	float				yaw;
	enum e_input_mask	input_mask;
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

void	player_rotate(t_cub *cub, float angle);
void	player_move(t_cub *cub, float angle);

static struct s_input const	g_inputs[] = {
{XK_Escape, {INPUT_EXIT, NULL, 0.0f}},
{XK_w, {INPUT_UP, player_move, 0.0f}},
{XK_s, {INPUT_DOWN, player_move, M_PI}},
{XK_a, {INPUT_LEFT, player_move, -M_PI_2}},
{XK_d, {INPUT_RIGHT, player_move, M_PI_2}},
{XK_Left, {INPUT_CAM_LEFT, player_rotate, -M_PI_2}},
{XK_Right, {INPUT_CAM_RIGHT, player_rotate, M_PI_2}},
};

struct s_input const	*get_input(int key);

#endif
