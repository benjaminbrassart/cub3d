/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_key_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:06:02 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/12 15:11:33 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "mlx_handle.h"

#include "mlx.h"

#include <X11/keysym.h>

int	input_key_handle(int key, t_cub *cub)
{
	if (key == XK_Escape)
		return (destroy_handle(cub));
	return (0);
}
