/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:18:33 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/12 15:33:55 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"
#include "def.h"

#include <stdlib.h>

int	main(int argc, char const *argv[])
{
	if (args_check(argc, argv) == RES_FAILURE)
		return (EXIT_FAILURE);
	
	return (EXIT_SUCCESS);
}
