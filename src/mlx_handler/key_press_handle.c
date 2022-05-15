/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:06:02 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/15 12:42:00 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "input.h"
#include "mlx_handle.h"

#include "mlx.h"

#include <stddef.h>

int	key_press_handle(int key, t_cub *cub)
{
	struct s_input const	*input = get_input(key);

	if (input == NULL)
		return (0);
	cub->player.input_mask |= input->action.mask;
	return (0);
}
