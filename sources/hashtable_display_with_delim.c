/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_display_with_delim.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 14:38:53 by niccheva          #+#    #+#             */
/*   Updated: 2016/09/06 14:38:56 by niccheva         ###   ########.fr       */
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
