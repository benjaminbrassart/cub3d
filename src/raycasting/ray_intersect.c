/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:24:08 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/16 20:25:54 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	ray_intersect(t_ray const *ray, float distance, t_vf2 *intersect)
{
	intersect->x = ray->start.x + ray->dir.x * distance;
	intersect->y = ray->start.y + ray->dir.y * distance;
}
