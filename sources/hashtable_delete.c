/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_delete.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 13:46:03 by llapillo          #+#    #+#             */
/*   Updated: 2016/07/11 12:32:45 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"
#include <stdlib.h>

void		hashtable_delete(t_hashtable *hashtable)
{
	t_hashtable		*entry;
	t_list			*pos;

	pos = (&(hashtable->list));
	while (&(hashtable->list) != (&(hashtable->list))->next)
	{
		entry = LIST_FIRST_ENTRY(pos, t_hashtable, list);
		if (entry)
		{
			hashtable_delete_entry(&entry);
		}
	}
	free(hashtable);
}
