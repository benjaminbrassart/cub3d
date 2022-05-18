/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:15:19 by msainton          #+#    #+#             */
/*   Updated: 2022/05/18 18:15:54 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "def.h"
#include "ft.h"
#include "parse.h"

#include <unistd.h>
#include <stdint.h>

int	custom_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\r');
}

void	texture(char *line, t_param *param, struct s_map *map)
{
	int	i;
	int	j;
	while (line[i] && custom_isspace(line[i]) != 0)
		i++;
	i += 2;
	while (line[i] && custom_isspace(line[i]) != 0)
		i++;
	j = 0;
	while (line[i + j])
		j++;
	param->textures[map->index] = ft_substr(line, i, j);
	return ;
}

int	parse_color(char *str)
{
	int			i;
	int			r;
	int			bytes;
	int			tmp;
	uint32_t	rgb;

	i = 0;
	bytes = 24;
	rgb = 0xFF << bytes;
	while (str[i])
	{
		r = 0;
		while (ft_isdigit(str[i + r]) != 0)
			r++;
		tmp = ft_atoi(ft_substr(str, i + r, r));
		if (tmp < 0 || tmp > 255)
			return (-1);
		rgb = rgb + (tmp << (bytes -8));
		i += r;
		if (str[i] != ',')
			return (-1);
		i++;
	}
	return (rgb);
}

void	color(char *line, t_param *param, struct s_map *map)
{
	int	i;
	int	j;
	
	while (line[i] && custom_isspace(line[i]) != 0)
		i++;
	i++;
	while (line[i] && custom_isspace(line[i]) != 0)
		i++;
	j = 0;
	while (line[i + j])
		j++;
	param->rgb[map->index] = parse_color(ft_substr(line, i, j));
}

int	check_luptable(char *line, t_param *param, struct s_map *map)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (line[i] && custom_isspace(line[i]) != 0)
		i++;
	k = 0;
	while (line[i + k] && custom_isspace(line[i]) == 0)
		k++;
	j = 0;
	while (j < (sizeof(g_map) / sizeof(*g_map)))
	{
		if (ft_strncmp(g_map[j], line + i, k) == 0)
			break ;
		j++;
	}
	if (g_map[j] == NULL)
		return (0);
	g_map[j].func(line, param, map);
	return (1);
}

int	check_map(int fd)
{
	t_param my_param;
	t_map 	map;
	char	*line;
	int		res;
	
	while (1)
	{
		res = get_next_line(fd, &line);
		if (res <= 0)
			break ;
		check_luptable(line, &my_param, &map);
	}
}