/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:09:52 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/15 18:25:59 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "mlx_handle.h"

#include "mlx.h"

int	destroy_handle(t_cub *cub)
{
	return (mlx_loop_end(cub->mlx));
}
