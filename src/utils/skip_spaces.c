/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_spaces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:15:41 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/03 08:40:25 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*skip_spaces(char const *s)
{
	char const	*p = s;

	while (ft_isspace(*p))
		++p;
	return ((char *)p);
}
