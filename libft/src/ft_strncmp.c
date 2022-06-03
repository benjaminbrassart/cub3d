/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 13:41:22 by bbrassar          #+#    #+#             */
/*   Updated: 2022/04/05 22:37:46 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_strncmp(char const *s1, char const *s2, size_t n)
{
	unsigned char const	*b1;
	unsigned char const	*b2;

	if (n == 0)
		return (0);
	b1 = (unsigned char const *)s1;
	b2 = (unsigned char const *)s2;
	while (--n && *b1 && *b2 && *b1 == *b2)
	{
		b1++;
		b2++;
	}
	return (*b1 - *b2);
}
