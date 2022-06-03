/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:15:41 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/03 08:43:51 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#include "ft.h"

char	*skip(char const *s, int (*pred)(int))
{
	char const	*p = s;

	while (pred(*p))
		++p;
	return ((char *)p);
}
