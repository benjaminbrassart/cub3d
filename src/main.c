/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:18:33 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/01 01:14:22 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"
#include "cub.h"
#include "def.h"
#include "lifecycle.h"
#include "parse.h"

#include "ft.h"

#include <stdlib.h>

int	main(int argc, char const *argv[])
{
	t_cub	cub;
	int		res;

	if (args_check(argc, argv) == RES_FAILURE)
		return (EXIT_FAILURE);
	ft_memset(&cub, 0, sizeof (cub));
	res = RES_FAILURE;
	cub.map_file = argv[1];
	if (cub_init(&cub))
		res = (cub_load(&cub) && cub_run(&cub));
	cub_destroy(&cub);
	if (res == RES_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
