/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_modify_elem.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 12:13:24 by llapillo          #+#    #+#             */
/*   Updated: 2016/07/11 14:24:02 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

void		hashtable_modify_elem(t_hashtable *elem, const char *key,
									const char *value)
{
	if (key)
	{
		if (elem->key)
			ft_strdel(&(elem->key));
		elem->key = ft_strdup(key);
	}
	if (value)
	{
		if (elem->value)
			ft_strdel(&(elem->value));
		elem->value = ft_strdup(value);
	}
}
