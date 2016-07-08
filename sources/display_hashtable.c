/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_hashtable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 13:40:12 by llapillo          #+#    #+#             */
/*   Updated: 2016/07/08 14:37:33 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"
#include "libft.h"

void	display_hashtable_with_delim(t_hashtable *hashtable, char *delim)
{
	t_hashtable		*entry;
	t_list			*pos;

	if (hashtable == NULL || delim == NULL)
		return ;
	pos = (&(hashtable->list))->next;
	while (pos != &(hashtable->list))
	{
		entry = LIST_ENTRY(pos, t_hashtable, list);
		if (entry)
		{
			ft_putstr(entry->key);
			ft_putstr(delim);
			ft_putendl(entry->value);
		}
		pos = pos->next;
	}
}
