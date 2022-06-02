/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:00:56 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/18 19:37:41 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "intlen.h"

char	*ft_itoa(int i)
{
	char			buffer[MAX_INT_LEN];
	unsigned int	n;
	unsigned int	count;

	if (i < 0)
		n = -i;
	else
		n = i;
	count = 0;
	while (n || count == 0)
	{
		buffer[MAX_INT_LEN - ++count] = n % 10 + '0';
		n /= 10;
	}
	if (i < 0)
		buffer[MAX_INT_LEN - ++count] = '-';
	return (ft_strndup(buffer + MAX_INT_LEN - count, count));
}
