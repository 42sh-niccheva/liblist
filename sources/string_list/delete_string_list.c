/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_string_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 08:34:03 by niccheva          #+#    #+#             */
/*   Updated: 2016/09/16 08:45:27 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_list.h"

void				delete_string_list(t_string_list *list)
{
	if (list)
	{
		while (&(list->list) != list->list.next)
		{
			delete_string_list_entry(LIST_FIRST_ENTRY(&(list->list), t_string_list, list));
		}
		delete_string_list_entry(list);
	}
}
