/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gettile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:54:34 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/02 08:05:08 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

#include "ft.h"

char	map_gettile(t_cub const *cub, int x, int y)
{
	unsigned int const	ux = (unsigned int)x;
	unsigned int const	uy = (unsigned int)y;

	if (uy >= 0 && uy < cub->map_height && ux >= 0 && ux < cub->map_lengths[uy])
		return (cub->map[uy][ux]);
	return (0);
}
