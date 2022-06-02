/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 10:16:19 by bbrassar          #+#    #+#             */
/*   Updated: 2022/04/05 22:37:46 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_strchr(char const *s, int c)
{
	unsigned char	ch;
	size_t			len;
	size_t			i;

	ch = c;
	len = ft_strlen(s);
	i = 0;
	while (i <= len)
	{
		if (s[i] == ch)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
