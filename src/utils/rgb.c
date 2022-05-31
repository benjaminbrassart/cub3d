/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 18:30:06 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/15 18:34:47 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

uint32_t	rgb(uint8_t r, uint8_t g, uint8_t b)
{
	return ((0xFF << 24) | (r << 16) | (g << 8) | (b << 0));
}

uint32_t	rgba(uint8_t r, uint8_t g, uint8_t b, float alpha)
{
	uint8_t	a;

	if (alpha > 1.0f)
		alpha = 1.0f;
	if (alpha < 0.0f)
		alpha = 0.0f;
	a = (alpha * 255);
	return ((a << 24) | (r << 16) | (g << 8) | (b << 0));
}
