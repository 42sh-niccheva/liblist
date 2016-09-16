/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 21:49:25 by niccheva          #+#    #+#             */
/*   Updated: 2016/09/16 08:42:12 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_LIST_H
# define STRING_LIST_H

# include "list.h"
# include <stddef.h>

typedef struct s_string_list	t_string_list;

struct							s_string_list
{
	char						*str;
	t_list						list;
};

t_string_list					*create_string_list(const char *s);
void							delete_string_list(t_string_list *list);
void							delete_string_list_entry(t_string_list *list);
void							string_list_add(t_string_list *list, t_string_list *new);
size_t							string_list_size(const t_string_list *list);

#endif
