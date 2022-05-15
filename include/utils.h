/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 18:28:30 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/15 18:29:51 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdint.h>

uint32_t	rgb(uint8_t r, uint8_t g, uint8_t b);
uint32_t	rgba(uint8_t r, uint8_t g, uint8_t b, float alpha);

#endif
