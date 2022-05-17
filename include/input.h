/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:13:05 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/17 16:50:12 by bbrassar         ###   ########.fr       */
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
# define INPUT_SPRINT		INPUT_SPRINT

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
	INPUT_SPRINT	= (1 << 7),
};

struct s_factors
{
	int	x;
	int	y;
	int	yaw;
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
{.key = XK_Escape, .action.mask = INPUT_EXIT},
{.key = XK_w, .action.factors = {0, -1, 0}, .action.mask = INPUT_UP},
{.key = XK_s, .action.factors = {0, 1, 0}, .action.mask = INPUT_DOWN},
{.key = XK_a, .action.factors = {-1, 0, 0}, .action.mask = INPUT_LEFT},
{.key = XK_d, .action.factors = {1, 0, 0}, .action.mask = INPUT_RIGHT},
{.key = XK_Left, .action.factors = {0, 0, -1}, .action.mask = INPUT_CAM_LEFT},
{.key = XK_Right, .action.factors = {0, 0, 1}, .action.mask = INPUT_CAM_RIGHT},
};

struct s_input const	*get_input(int key);

#endif
