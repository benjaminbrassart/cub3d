/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 02:12:32 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/01 03:47:00 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "cuberr.h"
#include "parse.h"

#include <errno.h>
#include <string.h>

int	texture(char const *line, t_cub *cub, t_lut_parser const *lut)
{
	if (cub->textures[lut->index].img != NULL)
	{
		print_error(lut->elem, "duplicated identifier");
		return (RES_FAILURE);
	}
	if (canvas_load(cub, line, &cub->textures[lut->index]) == NULL)
	{
		print_error(line, strerror(errno));
		return (RES_FAILURE);
	}
	return (RES_SUCCESS);
}
