/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:16:17 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/26 13:46:17 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

// window width (pixels)
# define WIN_WIDTH			800
// window height (pixels)
# define WIN_HEIGHT			600
// window title (string)
# define WIN_TITLE			"CUB3D"

// size of a tile on the minimap (pixels)
# define MM_TILE_SIZE		8

// player hitbox size (distance)
# define PLAYER_HITBOX		0.2

// player position movement speed (distance)
# define MOVEMENT_SPEED		0.04f
// player camera angle speed (radians)
# define CAMERA_SPEED		0.08f

// maximum distance of a projection drawing ray (distance)
# define RENDER_DISTANCE	100.0f

#endif
