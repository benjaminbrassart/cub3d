/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 03:47:26 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/02 10:39:24 by msainton         ###   ########.fr       */
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

static void	_free_str(char *s);
static int	_set_map_dimensions(t_cub *cub);
static int	_cleanup(t_cub *cub, t_strlst **lst);
static int	_handle_error(int fd, char *line, t_strlst **lst);

int	parse_map_content(t_cub *cub, int fd)
{
	char		*line;
	char		*s;
	int			gnl;
	t_strlst	*lst;

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
		s = line;
		while (*s != 0 && ft_strchr(MAP_TILES, *s) != NULL)
			++s;
		if (*s != 0)
		{
			print_error("map", "invalid tile");
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
	strlst_delete(lst, _free_str);
	free(line);
	return (RES_FAILURE);
}

static void	_free_str(char *s)
{
	free(s);
}

static int	_set_map_dimensions(t_cub *cub)
{
	size_t	n;

	cub->map_lengths = malloc(cub->map_height * sizeof (*cub->map_lengths));
	if (cub->map_lengths == NULL)
		return (0);
	n = 0;
	while (n < cub->map_height)
	{
		cub->map_lengths[n] = ft_strlen(cub->map[n]);
		++n;
	}
	return (1);
}

static int	_cleanup(t_cub *cub, t_strlst **lst)
{
	cub->map = strlst_toarray(*lst);
	if (cub->map == NULL || !_set_map_dimensions(cub))
	{
		print_error(NULL, strerror(errno));
		strlst_delete(lst, _free_str);
		return (RES_FAILURE);
	}
	strlst_delete(lst, NULL);
	return (RES_SUCCESS);
}
