/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:13:58 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/12 15:15:21 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "def.h"
#include "lifecycle.h"

#include "mlx.h"

int	cub_run(t_cub *cub)
{
	mlx_loop(cub->mlx);
	return (RES_SUCCESS);
}
