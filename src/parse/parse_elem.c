/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:56:58 by msainton          #+#    #+#             */
/*   Updated: 2022/05/31 12:06:05 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "def.h"
#include "ft.h"
#include "parse.h"

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
