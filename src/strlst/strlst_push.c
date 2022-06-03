/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlst_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 01:23:40 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/01 04:04:46 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_list.h"

#include <stddef.h>
#include <stdlib.h>

int	strlst_push(t_strlst **head, char *value)
{
	t_strlst	*new_node;
	t_strlst	*it;

	if (head == NULL)
		return (0);
	new_node = malloc(sizeof (*new_node));
	if (new_node == NULL)
		return (0);
	new_node->value = value;
	new_node->next = NULL;
	if (*head == NULL)
		*head = new_node;
	else
	{
		it = *head;
		while (it->next)
			it = it->next;
		it->next = new_node;
	}
	return (1);
}
