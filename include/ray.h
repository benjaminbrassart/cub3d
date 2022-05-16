/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:57:54 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/16 21:56:56 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "player.h"

# include <stdbool.h>

typedef struct s_ray	t_ray;
typedef struct s_vf2	t_vf2;
typedef struct s_vi2	t_vi2;

struct s_vf2
{
	float	x;
	float	y;
};

struct s_vi2
{
	int	x;
	int	y;
};

struct s_ray
{
	t_vf2	start;
	t_vf2	dir;
	t_vf2	length;
	t_vf2	unit;
	t_vf2	step;
	t_vi2	check;
};

void	ray_init(t_ray *ray, t_player const *player, float yaw);
void	ray_intersect(t_ray const *ray, float distance, t_vf2 *intersect);
bool	ray_cast(t_ray *ray, float *distance, float *x, float *y);

#endif
