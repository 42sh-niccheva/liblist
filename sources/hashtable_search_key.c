/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_search_key.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 15:00:43 by llapillo          #+#    #+#             */
/*   Updated: 2016/07/11 15:16:47 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

int		hashtable_search_key(const t_hashtable *hashtable, const char *key)
{
	int				value;
	t_hashtable		*entry;
	t_list			*pos;

	value = 1;
	if (hashtable == NULL || key == NULL)
		return (-1);
	pos = (&(hashtable->list))->next;
	while (pos != &(hashtable->list))
	{
		entry = LIST_ENTRY(pos, t_hashtable, list);
		if (!ft_strcmp(entry->key, key))
		{
			value = 0;
			break ;
		}
		pos = pos->next;
	}
	return (value);
}
