/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:39:06 by bbrassar          #+#    #+#             */
/*   Updated: 2022/04/06 01:44:06 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_strstr(char const *haystack, char const *needle)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] && haystack[i + j] == needle[j])
			++j;
		if (!needle[j])
			return ((char *)haystack + i);
		++i;
	}
	return (NULL);
}
