/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:13:05 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/12 19:21:16 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# define EXIT 1
# define NO_EXIT 0

struct s_input_factors
{
	int	x;
	int	y;
	int	yaw;
};

struct s_input
{
	int	key;
	int	exits;
	struct s_factors
	{
		int	x;
		int	y;
		int	yaw;
	}	factors;
};

struct s_input const	*get_input(int key);

#endif
