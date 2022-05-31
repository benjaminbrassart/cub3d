/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:54:01 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/16 14:55:20 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#include <math.h>

float	ft_modf(float x, float y)
{
	float const	res = fmodf(x, y);

	if (res < 0)
		return (res + y);
	return (res);
}
