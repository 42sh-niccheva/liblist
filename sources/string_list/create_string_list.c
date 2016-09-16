/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_string_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 08:29:11 by niccheva          #+#    #+#             */
/*   Updated: 2016/09/16 08:32:34 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_list.h"
#include "libft.h"
#include <stdlib.h>

t_string_list		*create_string_list(const char *s)
{
	t_string_list	*list;

	list = (t_string_list *)malloc(sizeof(*list));
	if (list)
	{
		list->str = ft_strdup(s);
		init_list(&(list->list));
	}
	return (list);
}
