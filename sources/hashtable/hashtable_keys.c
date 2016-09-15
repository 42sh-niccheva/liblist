/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 09:01:02 by niccheva          #+#    #+#             */
/*   Updated: 2016/09/06 13:02:37 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

char			**hashtable_keys(const t_hashtable *hashtable)
{
	size_t		size;
	char		**keys;
	t_list		*pos;
	t_hashtable	*entry;

	keys = NULL;
	if (hashtable)
	{
		size = list_size(&(hashtable->list));
		keys = (char **)malloc((size * sizeof(*keys)) + 1);
		if (keys)
		{
			pos = hashtable->list.prev;
			ft_bzero(keys, (size * sizeof(*keys)) + 1);
			while (pos != &(hashtable->list))
			{
				--size;
				entry = LIST_ENTRY(pos, t_hashtable, list);
				keys[size] = ft_strdup(entry->key);
				pos = pos->prev;
			}
		}
	}
	return (keys);
}
