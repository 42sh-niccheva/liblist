/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hastable_create_from_tab.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 10:41:37 by llapillo          #+#    #+#             */
/*   Updated: 2016/07/08 14:58:41 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

static void			extract_data(const char *line, const char *delim,
								t_hashtable **elem)
{
	char		*ptr;
	size_t		size;

	if ((ptr = ft_strstr(line, delim)) != NULL)
	{
		size = ptr - line;
		(*elem)->key = ft_strndup(line, size);
		ptr += ft_strlen(delim);
		(*elem)->value = ft_strdup(ptr);
	}
}

static t_hashtable	*new_elem_hashtable(const char *line, const char *delim)
{
	t_hashtable	*new;

	new = (t_hashtable *)malloc(sizeof(t_hashtable));
	if (new)
	{
		new->key = NULL;
		new->value = NULL;
		if (line && delim)
			extract_data(line, delim, &new);
		init_list(&(new->list));
	}
	return (new);
}

t_hashtable			*hashtable_create_from_tab(const char **tab,
											const char *delim)
{
	t_hashtable	*hashtable;
	t_hashtable	*new;
	int			i;

	hashtable = NULL;
	if (tab && delim)
	{
		new = NULL;
		i = 0;
		if ((hashtable = new_elem_hashtable(NULL, NULL)) != NULL)
		{
			while (tab[i])
			{
				if ((new = new_elem_hashtable(tab[i], delim)) != NULL)
					list_add_tail(&(new->list), &(hashtable->list));
				i++;
			}
		}
	}
	return (hashtable);
}
