/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handle.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:00:22 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/12 18:14:09 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_HANDLE_H
# define MLX_HANDLE_H

# include "cub.h"

int	destroy_handle(t_cub *cub);
int	input_key_handle(int key, t_cub *cub);
int	loop_handle(t_cub *cub);

#endif
