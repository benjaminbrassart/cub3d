/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 03:42:32 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/01 03:48:59 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cuberr.h"
#include "def.h"
#include "parse.h"

#include "ft.h"

#include <errno.h>
#include <stdlib.h>
#include <string.h>

static void	_print_invalid_identifier(char const *line);
static int	_check_lut(char const *line, t_cub *cub);
static int	_is_empty(char const *line);

int	parse_map_params(t_cub *cub, int fd)
{
	char	*line;
	int		gnl;
	int		res;
	int		count;

	count = 0;
	while (count < 6)
	{
		gnl = get_next_line(fd, &line);
		if (gnl == 0)
			break ;
		if (gnl == -1)
		{
			print_error("reading", strerror(errno));
			return (RES_FAILURE);
		}
		if (_is_empty(line))
		{
			free(line);
			continue ;
		}
		res = _check_lut(line, cub);
		free(line);
		if (res != RES_SUCCESS)
			return (RES_FAILURE);
		++count;
	}
	return (RES_SUCCESS);
}


static void	_print_invalid_identifier(char const *line)
{
	char	*identifier;
	size_t	n;

	n = 0;
	while (!ft_isspace(line[n]))
		++n;
	identifier = ft_strndup(line, n);
	if (identifier == NULL)
		return ;
	print_error(identifier, "invalid identifier");
	free(identifier);
}

static int	_check_lut(char const *line, t_cub *cub)
{
	t_lut_parser const	*parser;

	while (ft_isspace(*line))
		++line;
	parser = g_lut_parser;
	while (parser->elem != NULL)
	{
		if (ft_strncmp(parser->elem, line, parser->length) == 0)
			break ;
		++parser;
	}
	if (parser->elem == NULL)
	{
		_print_invalid_identifier(line);
		return (RES_FAILURE);
	}
	line += parser->length;
	while (ft_isspace(*line))
		++line;
	return (parser->func(line, cub, parser));
}

static int	_is_empty(char const *line)
{
	while (ft_isspace(*line))
		++line;
	return (*line == 0);
}
