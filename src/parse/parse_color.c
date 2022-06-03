/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 02:12:30 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/03 13:29:08 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cuberr.h"
#include "parse.h"
#include "utils.h"

#include "ft.h"

#include <limits.h>

static uint32_t	_parse_color(char const *str, t_lut_parser const *lut);
static int		_parse_byte(char const **s, char const *elem, uint8_t *byte_p);

int	color(char const *line, t_cub *cub, t_lut_parser const *lut)
{
	if (cub->colors[lut->index] != 0)
	{
		print_error(lut->elem, ERROR_PARAM_DUP);
		return (RES_FAILURE);
	}
	cub->colors[lut->index] = _parse_color(line, lut);
	if (cub->colors[lut->index] == 0)
		return (RES_FAILURE);
	return (RES_SUCCESS);
}

static uint32_t	_parse_color(char const *str, t_lut_parser const *lut)
{
	int			offset;
	uint32_t	rgb;

	offset = 0;
	rgb = (0xFF << 24);
	while (offset < 3)
	{
		if (!_parse_byte(&str, lut->elem, ((uint8_t *)&rgb) + 2 - offset))
			return (0x00000000);
		if (++offset < 3)
			++str;
	}
	if (is_empty(str))
		return (rgb);
	print_error(lut->elem, ERROR_COLOR_TRAILING);
	return (0x00000000);
}

static int	_parse_byte(char const **s, char const *elem, uint8_t *byte_p)
{
	unsigned int	value;
	char const		*p;

	value = 0;
	*s = skip(*s, ft_isspace);
	p = *s;
	while (ft_isdigit(*p) && value <= UINT8_MAX)
	{
		value = value * 10 + *p - '0';
		++p;
	}
	p = skip(p, ft_isspace);
	if (value > UINT8_MAX)
		print_error(elem, ERROR_COLOR_BOUNDS);
	else if (*p != ',' && *p != 0)
		print_error(elem, ERROR_COLOR_FORMAT);
	else
	{
		*s = p;
		*byte_p = (uint8_t)value;
		return (RES_SUCCESS);
	}
	return (RES_FAILURE);
}
