/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 03:47:26 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/01 04:26:20 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cuberr.h"
#include "parse.h"
#include "string_list.h"

#include "ft.h"

#include <errno.h>
#include <stdlib.h>
#include <string.h>

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

int	parse_map_content(t_cub *cub, int fd)
{
	char		*line;
	int			gnl;
	t_strlst	*lst;

	lst = NULL;
	while (true)
	{
		gnl = get_next_line(fd, &line);
		if (gnl == 0)
			break ;
		if (gnl == -1)
		{
			print_error("reading", strerror(errno));
			return (RES_FAILURE);
		}
		if (!strlst_push(&lst, line))
		{
			free(line);
			print_error(NULL, strerror(errno));
			return (RES_FAILURE);
		}
		++cub->map_height;
	}
	return (_cleanup(cub, &lst));
}
