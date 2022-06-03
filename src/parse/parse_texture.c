/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 02:12:32 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/03 11:40:51 by bbrassar         ###   ########.fr       */
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
	char	*file;

	if (cub->textures[lut->index].img != NULL)
	{
		print_error(lut->elem, ERROR_PARAM_DUPLICATED);
		return (RES_FAILURE);
	}
	file = ft_strtrim_f(line, ft_isspace);
	if (file == NULL || canvas_load(cub, file,
			&cub->textures[lut->index]) == NULL)
	{
		free(file);
		print_syserror(lut->elem);
		return (RES_FAILURE);
	}
	free(file);
	return (RES_SUCCESS);
}
