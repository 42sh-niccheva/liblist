/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 10:23:04 by llapillo          #+#    #+#             */
/*   Updated: 2016/09/06 09:00:52 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_H
# define HASHTABLE_H

# include "list.h"
# include "libft.h"

typedef struct s_hashtable	t_hashtable;

struct			s_hashtable
{
	char		*key;
	char		*value;
	t_list		list;
};

void			hashtable_delete(t_hashtable *hashtable);
void			hashtable_delete_entry(t_hashtable **elem);
void			hashtable_display_with_delim(const t_hashtable *hashtable,
											const char *delim);
t_hashtable		*hashtable_create_from_tab(const char **tab, const char *delim);
char			**hashtable_create_to_tab(const t_hashtable *hashtable,
										const char *delim);
void			hashtable_modify_elem(t_hashtable *elem, const char *key,
									const char *value);
t_hashtable		*hashtable_new_elem(const char *line, const char *delim);
t_hashtable		*hashtable_search_key(const t_hashtable *hashtable,
									const char *key);

char			**hashtable_keys(const t_hashtable *hashtable);
char			**hashtable_values(const t_hashtable *hashtable);

#endif
