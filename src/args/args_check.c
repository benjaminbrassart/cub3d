/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:30:50 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/12 15:01:56 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"
#include "cuberr.h"
#include "def.h"

#include "ft.h"

#include <unistd.h>

int	args_check(int argc, char const *argv[])
{
	char	*ext;

	if (argc != 2)
	{
		print_error("usage", PROGNAME " <map.cub>");
		return (RES_FAILURE);
	}
	ext = ft_strrstr(argv[1], FILEEXT);
	if (ext == NULL || ft_strcmp(ext, FILEEXT) != 0)
	{
		print_error(argv[1], "File extension must be " FILEEXT);
		return (RES_FAILURE);
	}
	return (RES_SUCCESS);
}

