/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_list_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 08:40:39 by niccheva          #+#    #+#             */
/*   Updated: 2016/09/16 08:41:36 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_list.h"

void		string_list_add(t_string_list *list, t_string_list *new)
{
	list_add_tail(&(new->list), &(list->list));
}
