/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 18:28:30 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/03 10:57:47 by bbrassar         ###   ########.fr       */
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

int			ft_isnonspace(int c);
int			is_empty(char const *line);

char		*skip(char const *s, int (*pred)(int));
char		*ft_strtrim_f(char const *s, int (*pred)(int));

#endif
