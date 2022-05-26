/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gettile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:54:34 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/26 14:08:46 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "removeme.h"

#include "cub.h"

#include "ft.h"

// TODO
char	map_gettile(t_cub const *cub, int x, int y)
{
	(void)cub;

	if (y >= 0 && y < MAP_HEIGHT && x >= 0
		&& (unsigned int)x < ft_strlen(g_map[y]))
		return (g_map[y][x]);
	return (0);
}
