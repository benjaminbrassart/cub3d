/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:19:52 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/12 19:25:11 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

#include <stddef.h>
#include <X11/keysym.h>

static struct s_input const	g_inputs[] = {
{XK_w, NO_EXIT, {0, -1, 0}},
{XK_s, NO_EXIT, {0, 1, 0}},
{XK_a, NO_EXIT, {-1, 0, 0}},
{XK_d, NO_EXIT, {1, 0, 0}},
{XK_Left, NO_EXIT, {0, 0, -1}},
{XK_Right, NO_EXIT, {0, 0, 1}},
{XK_Escape, EXIT, {0, 0, 0}},
};

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
