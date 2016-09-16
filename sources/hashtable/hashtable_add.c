/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 13:42:30 by llapillo          #+#    #+#             */
/*   Updated: 2016/09/16 13:47:10 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

void	hashtable_add(t_hashtable *hashtable, t_hashtable *new)
{
	if (hashtable && new)
		list_add_tail(&(new->list), &(hashtable->list));
}
