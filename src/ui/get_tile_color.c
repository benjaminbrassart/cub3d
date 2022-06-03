/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tile_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:06:17 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/19 12:08:23 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

#include "ft.h"

struct s_tile_color const	*get_tile_color(char tile)
{
	int	i;

	i = 0;
	while (g_tile_colors[i].charset != NULL)
	{
		if (ft_strchr(g_tile_colors[i].charset, tile) != NULL)
			break ;
		++i;
	}
	return (&g_tile_colors[i]);
}
