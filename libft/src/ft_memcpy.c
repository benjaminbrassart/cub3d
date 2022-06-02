/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:31:32 by bbrassar          #+#    #+#             */
/*   Updated: 2022/04/05 22:37:46 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	*ft_memcpy(void *dst, void const *src, size_t len)
{
	unsigned char		*d;
	unsigned char const	*s;

	if (dst == NULL && src == NULL)
		return (NULL);
	d = dst;
	s = src;
	while (len--)
		*d++ = *s++;
	return (dst);
}
