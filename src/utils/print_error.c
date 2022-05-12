/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:36:42 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/12 11:43:06 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cuberr.h"

#include "ft.h"

#include <unistd.h>

void	print_error(char const *prefix, char const *msg)
{
	write(STDERR_FILENO, PROGNAME ": ", sizeof (PROGNAME) + 1);
	if (prefix != NULL)
	{
		write(STDERR_FILENO, prefix, ft_strlen(prefix));
		write(STDERR_FILENO, ": ", 2);
	}
	if (msg != NULL)
		write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\n", 1);
}
