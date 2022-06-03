/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:15:41 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/03 10:56:23 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#include "ft.h"

char	*skip(char const *s, int (*pred)(int))
{
	char const	*p = s;

	while (*p != 0 && pred(*p))
		++p;
	return ((char *)p);
}
