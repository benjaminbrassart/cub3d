/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 01:20:41 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/01 01:33:05 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_LIST_H
# define STRING_LIST_H

typedef struct s_strlst	t_strlst;

struct s_strlst
{
	char		*value;
	t_strlst	*next;
};

char	**strlst_toarray(t_strlst const *head);
int		strlst_push(t_strlst **head, char *value);
void	strlst_delete(t_strlst **head, void (*free_value)(char *));

#endif // STRING_LIST_H
