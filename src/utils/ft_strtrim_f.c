/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:41:35 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/03 10:58:52 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#include "ft.h"

char	*ft_strtrim_f(char const *s, int (*pred)(int))
{
	size_t	n;

	while (pred(*s))
		++s;
	n = ft_strlen(s);
	if (n == 0)
		return (ft_calloc(1, sizeof (*ft_strtrim_f)));
	--n;
	while (n > 0 && pred(s[n]))
		--n;
	if (n == 0)
		return (ft_calloc(1, sizeof (*ft_strtrim_f)));
	return (ft_strndup(s, n + 1));
}
