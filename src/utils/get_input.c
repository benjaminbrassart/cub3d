/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:19:52 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/15 12:39:50 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

#include <stddef.h>
#include <X11/keysym.h>

struct s_input const	*get_input(int key)
{
	unsigned int	i;

	i = 0;
	while (i < (sizeof (g_inputs) / sizeof (*g_inputs)))
	{
		if (g_inputs[i].key == key)
			return (&g_inputs[i]);
		++i;
	}
	return (NULL);
}
