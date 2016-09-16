/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hastable_create_from_tab.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 10:41:37 by llapillo          #+#    #+#             */
/*   Updated: 2016/09/16 14:22:08 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

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
		if ((hashtable = hashtable_new(NULL, NULL)) != NULL)
		{
			while (tab[i])
			{
				new = hashtable_new_elem(tab[i], delim);
				hashtable_add(hashtable, new);
				i++;
			}
		}
	}
	return (hashtable);
}
