/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 09:52:27 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/18 19:36:45 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

#include <stdlib.h>

char	*ft_strdup(char const *s)
{
	size_t	n;
	char	*str;

	n = ft_strlen(s);
	str = malloc((n + 1) * (sizeof (*str)));
	if (str)
		ft_memcpy(str, s, n + 1);
	return (str);
}
