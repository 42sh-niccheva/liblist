/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_values.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 09:01:02 by niccheva          #+#    #+#             */
/*   Updated: 2016/09/06 13:03:11 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

char			**hashtable_values(const t_hashtable *hashtable)
{
	size_t		size;
	char		**values;
	t_list		*pos;
	t_hashtable	*entry;

	values = NULL;
	if (hashtable)
	{
		size = list_size(&(hashtable->list));
		values = (char **)malloc((size * sizeof(*values)) + 1);
		if (values)
		{
			pos = hashtable->list.prev;
			ft_bzero(values, (size * sizeof(*values)) + 1);
			while (pos != &(hashtable->list))
			{
				--size;
				entry = LIST_ENTRY(pos, t_hashtable, list);
				values[size] = ft_strdup(entry->value);
				pos = pos->prev;
			}
		}
	}
	return (values);
}
