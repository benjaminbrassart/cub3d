/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anex_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:52:59 by msainton          #+#    #+#             */
/*   Updated: 2022/05/31 11:57:04 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "def.h"
#include "ft.h"
#include "parse.h"

int	check_pos(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
			return (1);
		i++;
	}
	return (0);
}

int	custom_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\r');
}
