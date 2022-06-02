/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:26:24 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/01 08:26:22 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>
#include <unistd.h>

static void	_gnl_join(char **line, char *buffer, size_t n);
static int	_gnl_copy(char **line, char *buffer, char **rest);
static int	_gnl_init(char **line, char *rest);

int	get_next_line(int fd, char **line)
{
	static char	*rest = NULL;
	char		*buffer;
	int			bytes;

	bytes = _gnl_init(line, rest);
	if (bytes <= 0)
		return (bytes);
	if (rest)
		if (_gnl_copy(line, ft_strdup(rest), &rest))
			return (1);
	while (bytes > 0)
	{
		buffer = malloc(sizeof (char) * (BUFFER_SIZE + 1));
		bytes = read(fd, ft_memset(buffer, 0, BUFFER_SIZE + 1), BUFFER_SIZE);
		if (bytes == -1)
			free(buffer);
		else if (_gnl_copy(line, buffer, &rest))
			return (1);
	}
	if (bytes == 0 && (*line == NULL || **line == 0))
	{
		free(*line);
		line = NULL;
	}
	return (bytes);
}

static void	_gnl_join(char **line, char *buffer, size_t n)
{
	size_t	i;
	char	*s;

	i = 0;
	while (*line && (*line)[i])
		++i;
	s = malloc(i + n + 1);
	if (s)
	{
		ft_memmove(s, *line, i);
		ft_memmove(s + i, buffer, n);
		s[i + n] = 0;
		free(*line);
		*line = s;
	}
}

static int	_gnl_copy(char **line, char *buffer, char **rest)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		++i;
	_gnl_join(line, buffer, i);
	free(*rest);
	if (buffer[i])
		*rest = ft_strdup(buffer + i + 1);
	else
		*rest = NULL;
	i = !!buffer[i];
	free(buffer);
	return (i);
}

static int	_gnl_init(char **line, char *rest)
{
	if (BUFFER_SIZE < 1)
		return (-1);
	if (line == NULL)
	{
		free(rest);
		return (0);
	}
	*line = NULL;
	return (1);
}
