/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hastable_create_to_tab.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 10:41:37 by llapillo          #+#    #+#             */
/*   Updated: 2016/09/06 14:56:54 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

static void			fill_tab(char **tab, const t_hashtable *hashtable,
							const char *delim)
{
	size_t			i;
	t_list			*pos;
	size_t			size;
	t_hashtable		*entry;

	i = 0;
	size = 0;
	pos = (&(hashtable->list))->next;
	while (pos != &(hashtable->list))
	{
		entry = LIST_ENTRY(pos, t_hashtable, list);
		size = ft_strlen(delim) + ft_strlen(entry->key)
			+ ft_strlen(entry->value);
		tab[i] = ft_strnew(size);
		tab[i] = ft_strcat(tab[i], entry->key);
		tab[i] = ft_strcat(tab[i], delim);
		tab[i] = ft_strcat(tab[i], entry->value);
		++i;
		pos = pos->next;
	}
}

char				**hashtable_create_to_tab(const t_hashtable *hashtable,
											const char *delim)
{
	char	**tab;
	size_t	size;

	size = list_size(&hashtable->list);
	tab = (char **)malloc(sizeof(*tab) * (size + 1));
	tab[size] = NULL;
	fill_tab(tab, hashtable, delim);
	return (tab);
}
