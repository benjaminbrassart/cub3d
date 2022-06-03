/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 18:28:30 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/03 08:16:52 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdint.h>

struct s_factors
{
	int	x;
	int	y;
	int	yaw;
};

uint32_t	rgb(uint8_t r, uint8_t g, uint8_t b);
uint32_t	rgba(uint8_t r, uint8_t g, uint8_t b, float alpha);

void		swapi(int *x, int *y);

float		ft_modf(float x, float y);

void		factors_add(struct s_factors const *src, struct s_factors *dest);

int			is_empty(char const *line);

char		*skip_spaces(char const *s);

#endif
