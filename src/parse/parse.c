/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:15:19 by msainton          #+#    #+#             */
/*   Updated: 2022/05/31 11:57:41 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "def.h"
#include "ft.h"
#include "parse.h"

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
	
	ft_memset(&my_param, 0, sizeof (my_param));
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
