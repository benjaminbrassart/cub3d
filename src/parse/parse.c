/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:15:19 by msainton          #+#    #+#             */
/*   Updated: 2022/05/15 01:18:48 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "def.h"

#include <unistd.h>


void	check_line(char *line)
{
	
}

int	check_map(int fd)
{
	char	*line;
	int		res;
	
	while (1)
	{
		res = get_next_line(fd, &line);
		if (res <= 0)
			break ;
		check_line(line);
	}
	
}