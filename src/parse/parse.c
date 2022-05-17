/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:15:19 by msainton          #+#    #+#             */
/*   Updated: 2022/05/17 12:39:35 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "def.h"
#include "ft.h"
#include "parse.h"

#include <unistd.h>

int	custom_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\r');
}

int	texture(char *line, t_param *param, struct s_map *map)
{
	int	i;
	int	j;
	char	*tmp;
	char	*tmp2;

	i = 0;
	while (line[i] && custom_isspace(line[i]) != 0)
		i++;
	j = 0;
	while (line[i] && custom_isspace(line[i]) == 0)
	{
		tmp[j] == line[i];
		i++;
	}
	j = 0;
	while (j < (sizeof(g_map) / sizeof(*g_map)))
	{
		if (tmp == g_map[j])
			break;
		j++;
	}
	if (g_map[j] == NULL)
		return (0);
	while (line[i] && custom_isspace(line[i]) != 0)
		i++;
	j = 0;
	while (line[i])
		tmp2[j++] = line[i++];
	param->textures[map->index] = tmp2;
	return (1);
}

int	parse_rgb(char *str, t_param *param, struct s_map *map)
{
	int		i;
	int		j;
	int		k;
	char	*tmp;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] >= '0' && str[i] <= '9')
			tmp[k++] = str[i++];
		if (str[i] == ',')
		{
			i++;
			param->rgb[map->index + j] = ft_atoi(tmp);
			j++;
		}
		else
			break;
	}
}

int	color(char *line, t_param *param, struct s_map *map)
{
	int		i;
	int		j;
	char	*tmp;
	char	*tmp2;

	i = 0;
	while (line[i] && custom_isspace(line[i]) != 0)
		i++;
	j = 0;
	while (line[i] && custom_isspace(line[i]) == 0)
	{
		tmp[j] == line[i];
		i++;
	}
	j = 0;
	while (j < (sizeof(g_map) / sizeof(*g_map)))
	{
		if (tmp == g_map[j])
			break;
		j++;
	}
	if (g_map[j] == NULL)
		return (0);
	while (line[i] && custom_isspace(line[i]) != 0)
		i++;
	j = 0;
	while (line[i] && custom_isspace(line[i]) == 0)
		tmp2[j++] = line[i++];
	if (parse_rgb(tmp2, param, map) == RES_FAILURE);
		return (RES_FAILURE);
	return (RES_SUCCESS);
}

int	check_map(int fd)
{
	t_map	array;
	char	*line;
	int		res;
	
//	init_array(&array);
	while (1)
	{
		res = get_next_line(fd, &line);
		if (res <= 0)
			break ;
		
	}
}