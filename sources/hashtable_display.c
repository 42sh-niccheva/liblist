/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 13:40:12 by llapillo          #+#    #+#             */
/*   Updated: 2016/07/11 14:33:23 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"
#include "libft.h"

void	hashtable_display_with_delim(const t_hashtable *hashtable,
									const char *delim)
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
