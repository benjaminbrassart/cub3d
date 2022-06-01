/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlst_toarray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 01:32:17 by bbrassar          #+#    #+#             */
/*   Updated: 2022/06/01 04:22:31 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_list.h"

#include "ft.h"

#include <stdlib.h>

static size_t	strlst_length(t_strlst const *head);

char	**strlst_toarray(t_strlst const *head)
{
	size_t const	len = strlst_length(head);
	char			**array;
	size_t			i;

	array = malloc((len + 1) * sizeof (*array));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		array[i] = head->value;
		head = head->next;
		++i;
	}
	array[i] = NULL;
	return (array);
}

static size_t	strlst_length(t_strlst const *head)
{
	size_t	len;


	len = 0;
	while (head != NULL)
	{
		head = head->next;
		++len;
	}
	return (len);
}
