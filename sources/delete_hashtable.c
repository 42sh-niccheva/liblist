/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_hashtable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 13:46:03 by llapillo          #+#    #+#             */
/*   Updated: 2016/07/08 15:26:30 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"
#include "libft.h"
#include <stdlib.h>

void		delete_hashtable(t_hashtable *hashtable)
{
	t_hashtable		*entry;
	t_list			*pos;

	pos = (&(hashtable->list));
	while (&(hashtable->list) != (&(hashtable->list))->next)
	{
		entry = LIST_FIRST_ENTRY(pos, t_hashtable, list);
		if (entry)
		{
			ft_strdel(&(entry->key));
			ft_strdel(&(entry->value));
			list_del(&(entry->list));
			free(entry);
		}
	}
	free(hashtable);
}
