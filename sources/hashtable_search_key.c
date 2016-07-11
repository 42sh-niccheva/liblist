/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_search_key.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 15:00:43 by llapillo          #+#    #+#             */
/*   Updated: 2016/07/11 16:04:27 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

t_hashtable	*hashtable_search_key(const t_hashtable *hashtable, const char *key)
{
	t_hashtable		*entry;
	t_hashtable		*elem;
	t_list			*pos;

	elem = NULL;
	if (hashtable == NULL || key == NULL)
		return (elem);
	pos = (&(hashtable->list))->next;
	while (pos != &(hashtable->list))
	{
		entry = LIST_ENTRY(pos, t_hashtable, list);
		if (!ft_strcmp(entry->key, key))
		{
			elem = entry;
			break ;
		}
		pos = pos->next;
	}
	return (elem);
}
