/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifecycle.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:22:50 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/12 16:22:31 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIFECYCLE_H
# define LIFECYCLE_H

# include "cub.h"

int		cub_init(t_cub *cub);
int		cub_load(t_cub *cub);
int		cub_run(t_cub *cub);
void	cub_destroy(t_cub *cub);

#endif
