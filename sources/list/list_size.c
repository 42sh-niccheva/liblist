/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 09:30:07 by niccheva          #+#    #+#             */
/*   Updated: 2016/09/06 09:31:58 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

size_t		list_size(const t_list *head)
{
	size_t	size;
	t_list	*pos;

	size = 0;
	if (head)
	{
		pos = head->next;
		while (pos != head)
		{
			++size;
			pos = pos->next;
		}
	}
	return (size);
}
