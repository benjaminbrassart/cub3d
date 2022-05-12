/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cuberr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:36:48 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/12 11:44:06 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBERR_H
# define CUBERR_H

# include "def.h"

/**
 * Print a message on the standard error, followed by a newline
 *
 * format: "PROGNAME: prefix: msg"
 */
void	print_error(char const *prefix, char const *msg);

#endif
