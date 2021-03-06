/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:08:45 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/16 12:09:06 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	swapi(int *x, int *y)
{
	*x ^= *y;
	*y ^= *x;
	*x ^= *y;
}
