/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:13:05 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/01 09:22:52 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# define EXIT 1
# define INPUT_INIT			INPUT_INIT
# define INPUT_EXIT			INPUT_EXIT
# define INPUT_UP			INPUT_UP
# define INPUT_DOWN			INPUT_DOWN
# define INPUT_LEFT			INPUT_LEFT
# define INPUT_RIGHT		INPUT_RIGHT
# define INPUT_CAM_LEFT		INPUT_CAM_LEFT
# define INPUT_CAM_RIGHT	INPUT_CAM_RIGHT

# include "utils.h"

# include <X11/keysym.h>

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
		struct s_factors	factors;
	}	action;
};

static struct s_input const	g_inputs[] = {
{XK_Escape, {INPUT_EXIT, {}}},
{XK_w, {INPUT_UP, {0, -1, 0}}},
{XK_s, {INPUT_DOWN, {0, 1, 0}}},
{XK_a, {INPUT_LEFT, {-1, 0, 0}}},
{XK_d, {INPUT_RIGHT, {1, 0, 0}}},
{XK_Left, {INPUT_CAM_LEFT, {0, 0, -1}}},
{XK_Right, {INPUT_CAM_RIGHT, {0, 0, 1}}},
};

struct s_input const	*get_input(int key);

#endif
