/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:40:12 by bbrassar          #+#    #+#             */
/*   Updated: 2022/04/05 22:37:46 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_memcmp(void const *s1, void const *s2, size_t n)
{
	unsigned char const	*b1 = s1;
	unsigned char const	*b2 = s2;

	if (n == 0 || (s1 == NULL && s2 == NULL))
		return (0);
	while (--n && *b1 == *b2)
	{
		b1++;
		b2++;
	}
	return (*b1 - *b2);
}
