/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hastable_create_to_tab.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 10:41:37 by llapillo          #+#    #+#             */
/*   Updated: 2016/07/08 16:24:28 by llapillo         ###   ########.fr       */
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
		i++;
		pos = pos->next;
	}
}

static size_t		size_of_hashtable(const t_hashtable *hashtable)
{
	size_t			size;
	t_list			*pos;

	size = 0;
	pos = (&(hashtable->list))->next;
	while (pos != &(hashtable->list))
	{
		size++;
		pos = pos->next;
	}
	return (size);
}

char				**hashtable_create_to_tab(const t_hashtable *hashtable,
											const char *delim)
{
	char	**tab;
	size_t	size;

	size = size_of_hashtable(hashtable);
	tab = (char **)malloc(sizeof(char *) * (size + 1));
	tab[size] = 0;
	fill_tab(tab, hashtable, delim);
	return (tab);
}
