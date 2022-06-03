/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:36:42 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/03 11:41:19 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cuberr.h"

#include "ft.h"

#include <errno.h>
#include <string.h>
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

void	print_syserror(char const *prefix)
{
	int const	errnum = errno;
	char const	*msg;

	if (errnum == 0)
		return ;
	msg = strerror(errno);
	write(STDERR_FILENO, PROGNAME ": ", sizeof (PROGNAME) + 1);
	if (prefix != NULL)
	{
		write(STDERR_FILENO, prefix, ft_strlen(prefix));
		write(STDERR_FILENO, ": ", 2);
	}
	write(STDERR_FILENO, msg, ft_strlen(msg));
	msg = errno_name(errnum);
	if (msg != NULL)
	{
		write(STDERR_FILENO, " (", 2);
		if (msg)
			write(STDERR_FILENO, msg, ft_strlen(msg));
		write(STDERR_FILENO, ")\n", 2);
	}
}
