/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 03:47:26 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/03 10:33:38 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cuberr.h"
#include "parse.h"
#include "string_list.h"
#include "utils.h"

#include "ft.h"

#include <errno.h>
#include <stdlib.h>
#include <string.h>

static int	_cleanup(t_cub *cub, t_strlst **lst);
static int	_handle_error(int fd, char *line, t_strlst **lst);

int	parse_map_content(t_cub *cub, int fd)
{
	char		*line;
	char		*pers;
	int			gnl;
	t_strlst	*lst;
	int			i;

	line = NULL;
	while (true)
	{
		gnl = get_next_line(fd, &line);
		if (gnl == 0)
			break ;
		if (gnl == -1)
		{
			print_error("reading", strerror(errno));
			return (_handle_error(fd, NULL, &lst));
		}
		if (!is_empty(line))
			break ;
		free(line);
	}
	lst = NULL;
	while (true)
	{
		if (line == NULL)
			gnl = get_next_line(fd, &line);
		if (gnl == 0)
			break ;
		if (gnl == -1)
		{
			print_error("reading", strerror(errno));
			return (_handle_error(fd, NULL, &lst));
		}
		pers = ft_strpbrk(line, MAP_PERS);
		if (pers != NULL)
		{
			cub->player.x = pers - line;
			cub->player.y = cub->map_height;
			i = 0;
			while (MAP_PERS[i] != *pers)
				++i;
			cub->player.yaw = i * M_PI_2;
		}
		if (cub->player.x < 0 && cub->player.y < 0)
		{
			print_error("map", ERROR_MAP_SPAWN_DUPLICATED);
			return (_handle_error(fd, line, &lst));
		}
		if (ft_strpbrk(line, MAP_TILES) == NULL)
		{
			print_error("map", ERROR_MAP_INVALID_TILE);
			return (_handle_error(fd, line, &lst));
		}
		if (!strlst_push(&lst, line))
		{
			print_error(NULL, strerror(errno));
			return (_handle_error(fd, line, &lst));
		}
		++cub->map_height;
		line = NULL;
	}
	return (_cleanup(cub, &lst));
}

static int	_handle_error(int fd, char *line, t_strlst **lst)
{
	get_next_line(fd, NULL);
	strlst_delete(lst, free);
	free(line);
	return (RES_FAILURE);
}

static int	_cleanup(t_cub *cub, t_strlst **lst)
{
	size_t	n;

	if (cub->player.x < 0 || cub->player.y < 0)
	{
		print_error("map", ERROR_MAP_NO_SPAWN);
		return (RES_FAILURE);
	}
	cub->map = strlst_toarray(*lst);
	cub->map_lengths = malloc(cub->map_height * sizeof (*cub->map_lengths));
	if (cub->map == NULL || cub->map_lengths == NULL)
	{
		print_error(NULL, strerror(errno));
		strlst_delete(lst, free);
		free(cub->map);
		free(cub->map_lengths);
		return (RES_FAILURE);
	}
	n = 0;
	while (n < cub->map_height)
	{
		cub->map_lengths[n] = ft_strlen(cub->map[n]);
		++n;
	}
	strlst_delete(lst, NULL);
	return (RES_SUCCESS);
}
