/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_new_elem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 10:49:47 by llapillo          #+#    #+#             */
/*   Updated: 2016/09/06 14:39:40 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

static void		extract_data(const char *line, const char *delim,
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

t_hashtable		*hashtable_new_elem(const char *line, const char *delim)
{
	t_hashtable	*new;

	new = (t_hashtable *)malloc(sizeof(*new));
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
