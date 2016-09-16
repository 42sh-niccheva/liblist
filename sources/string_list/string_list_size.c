/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_list_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 08:41:43 by niccheva          #+#    #+#             */
/*   Updated: 2016/09/16 08:43:03 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_list.h"

size_t		string_list_size(const t_string_list *list)
{
	return (list_size(&(list->list)));
}
