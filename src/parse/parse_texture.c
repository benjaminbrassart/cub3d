/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 02:12:32 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/03 13:29:14 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "cuberr.h"
#include "parse.h"

#include "ft.h"

#include <errno.h>
#include <stdlib.h>
#include <string.h>

int	texture(char const *line, t_cub *cub, t_lut_parser const *lut)
{
	if (cub->textures[lut->index].img != NULL)
	{
		print_error(lut->elem, ERROR_PARAM_DUP);
		return (RES_FAILURE);
	}
	if (canvas_load(cub, line, &cub->textures[lut->index]) == NULL)
	{
		print_syserror(lut->elem);
		return (RES_FAILURE);
	}
	return (RES_SUCCESS);
}
