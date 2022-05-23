/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 04:39:06 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/23 04:45:47 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

#include "mlx.h"

#include <stddef.h>

t_canvas	*canvas_load(t_cub const *cub, char const *filename, t_canvas *out)
{
	if (out == NULL)
		return (NULL);
	out->img = mlx_xpm_file_to_image(cub->mlx, (char *)filename,
		(int *)&out->width, (int *)&out->height);
	if (out->img == NULL)
		return (NULL);
	out->raw = mlx_get_data_addr(out->img, &out->bpp, &out->line_len,
		&out->endian);
	if (out->raw == NULL)
		return (NULL);
	return (out);
}
