/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 02:12:30 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/01 03:47:11 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cuberr.h"
#include "parse.h"

#include "ft.h"

static uint32_t	_parse_color(char const *str, t_lut_parser const *lut);

int	color(char const *line, t_cub *cub, t_lut_parser const *lut)
{
	if (cub->colors[lut->index] != 0)
	{
		print_error(lut->elem, "duplicated identifier");
		return (RES_FAILURE);
	}
	cub->colors[lut->index] = _parse_color(line, lut);
	if (cub->colors[lut->index] == 0)
		return (RES_FAILURE);
	return (RES_SUCCESS);
}

static uint32_t	_parse_color(char const *str, t_lut_parser const *lut)
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
		if (nbr < 0 || nbr > 255)
		{
			print_error(lut->elem, "value out of bounds [0-255]");
			return (0);
		}
		bytes -= 8;
		str = end;
		if (bytes != 0 && *str++ != ',')
		{
			print_error(lut->elem, "invalid inner character");
			return (0);
		}
		rgb |= (nbr << (bytes));
	}
	while (*end)
	{
		if (bytes != 0 && ft_isspace(*end) == 0)
		{
			print_error(lut->elem, "invalid trailing character");
			return (0);
		}
		++end;
	}
	return (rgb);
}
