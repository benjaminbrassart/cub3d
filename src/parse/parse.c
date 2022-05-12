/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:15:19 by msainton          #+#    #+#             */
/*   Updated: 2022/05/12 16:25:58 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "def.h"

#include <unistd.h>

int	check_map(int fd)
{
	char	*line;
	int		res;
	
	while (res > 0)
	{
		if (res = get_next_line(fd, &line) == -1)
			return (RES_FAILURE);
		
	}
	
}