/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:15:19 by msainton          #+#    #+#             */
/*   Updated: 2022/05/27 20:46:43 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "def.h"
#include "ft.h"
#include "parse.h"

#include <unistd.h>
#include <stdint.h>

void	initialise(t_param *param)
{
	param->textures[0] == NULL;
	param->textures[1] == NULL;
	param->textures[2] == NULL;
	param->textures[3] == NULL;
	param->rgb[0] == 0;
	param->rgb[1] == 0;
}

int	custom_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\r');
}

int	texture(char *line, t_param *param, struct s_map *map)
{
	void	*mlx_ptr;
	int		width;
	int		height;

	param->textures[map->index] = mlx_xpm_file_to_image(mlx_ptr, line, width, height);
	if (param->textures[map->index] == NULL)
	{
		printf("%s" ERROR_TEXTURE);
		return (-1);
	}
	return (1);
}

int	parse_color(char *str)
{
	int			nbr;
	int			bytes;
	char		*end;
	uint32_t	rgb;

	bytes = 24;
	rgb = 0xFF << bytes;
	while (bytes != 0)
	{
		nbr = ft_strtoi(str, &end);
		if (nbr < 0 || nbr > 255 || bytes < 0)
			return (-1);
		if (bytes  == 0 && ft_isspace(end))
			break ;
		bytes -= 8;
		rgb = rgb + (nbr << (bytes));
	}
	while (*end)
	{
		if (bytes != 0 && ft_isspace(end) == 0)
			return (-1);
		*end++;
	}
	return (rgb);
}

int	color(char *line, t_param *param, struct s_map *map)
{
	param->rgb[map->index] = parse_color(line);
	if (param->rgb[map->index] == -1)
	{
		printf("%s" ERROR_COLORS);
		return (-1);
	}
	return (1);
	
}

int	check_luptable(char *line, t_param *param, struct s_map *map)
{
	int		i;
	int		j;
	int		k;
	int		l;

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
	{
		printf("%s", ERROR_IDENTIFIER);
		return (-1);
	}
	while (line[i + k + l] && custom_isspace(line[i]))
		l++;
	if (g_map[j].func(line + i + k + l, param, map) == -1)
		return (-1);
	return (1);
}

int	check_pos(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
			return (1);
		i++;
	}
	return (0);
}

int	parse_map(char *line, t_param *param)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (custom_isspace(line[i]))
		i++;
	if (line[i] == '\n')
		return (0);
	if (check_pos(param->map) == 1 && check_pos(line) == 1)
	{
		if (param->map)
			free(param->map);
		printf("%s", ERROR_MAP);
		return (-1);
	}
	while (line[i + j])
	{
		if (line[i + j] != '1'|| line != '0')
		{
			if (param->map)
				free(param->map);
			printf("%s", ERROR_MAP);
			return (-1);
		}
		j++;
	}
	param->map = ft_strjoin(param->map, line + i);
	return (1);
}

int	check_map(int fd)
{
	t_param my_param;
	t_map 	map;
	char	*line;
	int		res;
	int		i;
	
	initialise(&my_param);
	i = 0;
	while (1)
	{
		res = get_next_line(fd, &line);
		if (res <= 0)
			return (RES_FAILURE);
		if (check_luptable(line, &my_param, &map) != 1)
			return (RES_FAILURE);
		else
			i++;
		if (i == 6)
			break ;
	}
	while (1)
	{
		res = get_next_line(fd, &line);
		if (res <= 0)
			break ;
		if (parse_map(line, &my_param) != 1)
			return (RES_FAILURE);
	}
	
}