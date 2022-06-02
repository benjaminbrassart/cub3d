/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 10:34:42 by bbrassar          #+#    #+#             */
/*   Updated: 2022/04/05 22:37:46 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	*ft_memchr(void const *s, int c, size_t n)
{
	unsigned char const	*b = s;
	unsigned char const	ch = c;
	size_t				i;

	i = -1;
	while (++i < n)
	{
		if (b[i] == ch)
			return ((void *)b + i);
	}
	return (NULL);
}
