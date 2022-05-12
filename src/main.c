/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:18:33 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/12 14:26:48 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"
#include "cub.h"
#include "def.h"
#include "lifecycle.h"

#include <stdlib.h>

int	main(int argc, char const *argv[])
{
	t_cub	cub;
	int		res;

	if (args_check(argc, argv) == RES_FAILURE)
		return (EXIT_FAILURE);
	res = RES_FAILURE;
	if (cub_init(&cub))
		res = cub_run(&cub);
	cub_destroy(&cub);
	if (res == RES_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
