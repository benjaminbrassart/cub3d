/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handle.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:00:22 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/15 12:38:07 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_HANDLE_H
# define MLX_HANDLE_H

# include "cub.h"

int	destroy_handle(t_cub *cub);
int	key_press_handle(int key, t_cub *cub);
int	key_release_handle(int key, t_cub *cub);
int	loop_handle(t_cub *cub);

#endif
