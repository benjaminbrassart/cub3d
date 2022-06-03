/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 03:47:26 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/03 14:59:30 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cuberr.h"
#include "parse.h"
#include "string_list.h"
#include "utils.h"

#include "ft.h"

#include <errno.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

static int	_cleanup(t_cub *cub, t_strlst **lst);
static int	_handle_error(int fd, char *line, t_strlst **lst);
static int	_skip_empty(int fd, char **line, int *gnl_p);
static int	_check_line(t_cub *cub, char *line, t_strlst **lst);

int	parse_map_content(t_cub *cub, int fd)
{
	char		*line;
	int			gnl;
	t_strlst	*lst;

	lst = NULL;
	if (_skip_empty(fd, &line, &gnl) == 0)
		return (_handle_error(fd, line, &lst));
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
		if (!_check_line(cub, line, &lst))
			return (_handle_error(fd, line, &lst));
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

static int	_skip_empty(int fd, char **line, int *gnl_p)
{
	*line = NULL;
	while (true)
	{
		*gnl_p = get_next_line(fd, line);
		if (*gnl_p == 0)
			break ;
		if (*gnl_p == -1)
		{
			print_error("reading", strerror(errno));
			return (RES_FAILURE);
		}
		if (!is_empty(*line))
			break ;
		free(*line);
		*line = NULL;
	}
	return (RES_SUCCESS);
}

static int	_check_line(t_cub *cub, char *line, t_strlst **lst)
{
	char const	*pers = ft_strpbrk(line, MAP_PERS);
	int			i;

	if (pers != NULL)
	{
		if (cub->player.x >= 0 || ft_strpbrk(pers + 1, MAP_PERS) != NULL)
			return (print_error("map", ERROR_MAP_SPAWN_DUP), RES_FAILURE);
		cub->player.x = pers - line;
		cub->player.y = cub->map_height;
		i = 0;
		while (MAP_PERS[i] != *pers)
			++i;
		cub->player.yaw = i * M_PI_2;
	}
	if (!map_checkline(line))
		print_error("map", ERROR_MAP_INVALID_TILE);
	else if (!strlst_push(lst, line))
		print_error(NULL, strerror(errno));
	else
		return (RES_SUCCESS);
	return (0);
}
