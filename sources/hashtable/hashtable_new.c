/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 13:52:58 by llapillo          #+#    #+#             */
/*   Updated: 2016/09/16 14:01:58 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

t_hashtable			*hashtable_new(const char *key, const char *value)
{
	t_hashtable		*new;

	new = (t_hashtable *)malloc(sizeof(*new));
	if (new)
	{
		new->key = ft_strdup(key);
		new->value = ft_strdup(value);
		init_list(&(new->list));
	}
	return (new);
}
