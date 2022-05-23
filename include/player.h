/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:49:15 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/23 15:35:17 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "input.h"

typedef struct s_player	t_player;

struct s_player
{
	float				x;
	float				y;
	float				yaw;
	float				pitch;
	enum e_input_mask	input_mask;
};

#endif
