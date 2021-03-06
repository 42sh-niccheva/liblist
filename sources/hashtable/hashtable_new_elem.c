/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_new_elem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 10:49:47 by llapillo          #+#    #+#             */
/*   Updated: 2016/09/16 14:07:34 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

t_hashtable		*hashtable_new_elem(const char *line, const char *delim)
{
	t_hashtable	*new;
	char		*key;
	char		*value;
	char		*ptr;
	size_t		size;

	new = NULL;
	if ((ptr = ft_strstr(line, delim)) != NULL)
	{
		size = ptr - line;
		key = ft_strndup(line, size);
		ptr += ft_strlen(delim);
		value = ft_strdup(ptr);
		new = hashtable_new(key, value);
		ft_strdel(&key);
		ft_strdel(&value);
	}
	return (new);
}
