/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:18:33 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/31 11:29:58 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"
#include "cub.h"
#include "def.h"
#include "lifecycle.h"

#include "ft.h"

#include <stdlib.h>

int	main(int argc, char const *argv[])
{
	t_cub	cub;
	int		res;

	if (args_check(argc, argv) == RES_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
