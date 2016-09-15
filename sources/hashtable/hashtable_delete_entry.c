/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_delete_entry.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 12:26:46 by llapillo          #+#    #+#             */
/*   Updated: 2016/09/06 14:31:43 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"
#include "libft.h"
#include <stdlib.h>

void	hashtable_delete_entry(t_hashtable **elem)
{
	t_hashtable		*entry;

	entry = *elem;
	ft_strdel(&(entry->key));
	ft_strdel(&(entry->value));
	list_del(&(entry->list));
	free(entry);
	*elem = NULL;
}
