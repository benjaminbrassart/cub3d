/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:12:56 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/12 17:25:25 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

typedef struct s_cub	t_cub;

union u_file
{
	char const	*path;
	int			fd;
};

struct s_cub
{
	void			*mlx;
	void			*win;
	union u_file	map_file;
};

#endif
