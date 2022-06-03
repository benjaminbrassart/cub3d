/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlst_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 01:30:19 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/03 10:33:46 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_list.h"

#include <stdlib.h>

void	strlst_delete(t_strlst **head, void (*free_value)(void *))
{
	t_strlst	*fast;

	if (head == NULL)
		return ;
	while (*head != NULL)
	{
		fast = (*head)->next;
		if (free_value != NULL)
			free_value((*head)->value);
		free(*head);
		*head = fast;
	}
}
