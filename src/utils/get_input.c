/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:19:52 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/15 12:13:55 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

#include <stddef.h>
#include <X11/keysym.h>

static struct s_input const	g_inputs[] = {
{.key = XK_w, .action.factors = {0, -1, 0}},
{.key = XK_s, .action.factors = {0, 1, 0}},
{.key = XK_a, .action.factors = {-1, 0, 0}},
{.key = XK_d, .action.factors = {1, 0, 0}},
{.key = XK_Left, .action.factors = {0, 0, -1}},
{.key = XK_Right, .action.factors = {0, 0, 1}},
{.key = XK_Escape, .action.exits = EXIT},
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
