/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_search_key.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 15:00:43 by llapillo          #+#    #+#             */
/*   Updated: 2016/09/06 15:00:16 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

t_hashtable	*hashtable_search_key(const t_hashtable *hashtable, const char *key)
{
	t_hashtable		*entry;
	t_list			*pos;

	entry = NULL;
	if (hashtable == NULL || key == NULL)
		return (entry);
	pos = (&(hashtable->list))->next;
	while (pos != &(hashtable->list))
	{
		entry = LIST_ENTRY(pos, t_hashtable, list);
		if (ft_strequ(entry->key, key))
		{
			return (entry);
		}
		pos = pos->next;
	}
	return (NULL);
}
