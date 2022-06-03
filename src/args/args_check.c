/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:30:50 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/03 10:21:59 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"
#include "cuberr.h"
#include "def.h"

#include "ft.h"

#include <unistd.h>

int	args_check(int argc, char const *argv[])
{
	char		*ext;
	char const	*delim;

	if (argc != 2)
	{
		print_error("usage", ERROR_USAGE);
		return (RES_FAILURE);
	}
	delim = ft_strrchr(argv[1], '/');
	if (delim == NULL)
		delim = argv[1];
	else
		++delim;
	ext = ft_strrstr(delim, FILEEXT);
	if (ext == NULL || delim == ext || ft_strcmp(ext, FILEEXT) != 0)
	{
		print_error(delim, ERROR_EXTENSION FILEEXT);
		return (RES_FAILURE);
	}
	return (RES_SUCCESS);
}
