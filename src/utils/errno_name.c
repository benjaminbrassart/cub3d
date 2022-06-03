/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errno_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:32:28 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/03 11:36:40 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g_errno_name.h"

char	*errno_name(int errnum)
{
	struct s_errno_name const	*p;

	p = g_errno_name;
	while (p->errnum != 0)
	{
		if (errnum == p->errnum)
			break ;
		++p;
	}
	return (p->name);
}
