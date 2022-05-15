/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:13:05 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/15 12:10:24 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# define EXIT 1

struct s_input
{
	int	key;
	struct s_action
	{
		int	exits;
		struct s_factors
		{
			int	x;
			int	y;
			int	yaw;
		}	factors;
	}	action;
};

struct s_input const	*get_input(int key);

#endif
