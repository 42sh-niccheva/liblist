/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_string_list_entry.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 08:32:04 by niccheva          #+#    #+#             */
/*   Updated: 2016/09/16 08:33:49 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_list.h"
#include "libft.h"
#include <stdlib.h>

void		delete_string_list_entry(t_string_list *list)
{
	if (list)
	{
		ft_strdel(&(list->str));
		list_del(&(list->list));
		free(list);
	}
}
