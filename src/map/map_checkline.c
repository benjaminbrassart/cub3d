/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:53:59 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/03 14:58:05 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parse.h"

#include "ft.h"

int	map_checkline(char const *line)
{
	while (*line && ft_strchr(MAP_TILES, *line) != NULL)
		++line;
	return (*line == 0);
}
