/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_to_hashtable.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 10:23:04 by llapillo          #+#    #+#             */
/*   Updated: 2016/07/08 16:06:29 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAB_TO_HASHTABLE_H
# define TAB_TO_HASHTABLE_H

# include "list.h"
# include "libft.h"

typedef struct s_hashtable	t_hashtable;

struct			s_hashtable
{
	char		*key;
	char		*value;
	t_list		list;
};

void			delete_hashtable(t_hashtable *hashtable);
void			display_hashtable_with_delim(t_hashtable *hashtable,
											char *delim);
t_hashtable		*hashtable_create_from_tab(const char **tab, const char *delim);
char			**hashtable_create_to_tab(const t_hashtable *hashtable,
										const char *delim);

#endif
