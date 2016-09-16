#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/09 13:23:47 by niccheva          #+#    #+#              #
#    Updated: 2016/09/16 13:47:08 by llapillo         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	liblist.a

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

DSOURCES	=	./sources/

DOBJECTS	=	objects/

BUILD		=	./build

INCLUDES	=	-I./includes
INCLUDES	+=	-I../libft/includes

LISTPATH	=	list/
STRINGPATH	=	string_list/
HASHPATH	=	hashtable/

LIST		=	$(LISTPATH)init_list.c
LIST		+=	$(LISTPATH)list_add.c
LIST		+=	$(LISTPATH)list_add_tail.c
LIST		+=	$(LISTPATH)list_del.c
LIST		+=	$(LISTPATH)list_del_init.c
LIST		+=	$(LISTPATH)list_empty.c
LIST		+=	$(LISTPATH)list_is_last.c
LIST		+=	$(LISTPATH)list_is_singular.c
LIST		+=	$(LISTPATH)list_size.c
LIST		+=	$(LISTPATH)private_list_add.c
LIST		+=	$(LISTPATH)private_list_del.c
LIST		+=	$(LISTPATH)private_list_del_entry.c

STRING		=	$(STRINGPATH)create_string_list.c
STRING		+=	$(STRINGPATH)delete_string_list.c
STRING		+=	$(STRINGPATH)delete_string_list_entry.c
STRING		+=	$(STRINGPATH)string_list_add.c
STRING		+=	$(STRINGPATH)string_list_size.c

HASHTABLE	=	$(HASHPATH)hashtable_add.c
HASHTABLE	+=	$(HASHPATH)hashtable_create_from_tab.c
HASHTABLE	+=	$(HASHPATH)hashtable_create_to_tab.c
HASHTABLE	+=	$(HASHPATH)hashtable_display_with_delim.c
HASHTABLE	+=	$(HASHPATH)hashtable_delete.c
HASHTABLE	+=	$(HASHPATH)hashtable_delete_entry.c
HASHTABLE	+=	$(HASHPATH)hashtable_new_elem.c
HASHTABLE	+=	$(HASHPATH)hashtable_modify_elem.c
HASHTABLE	+=	$(HASHPATH)hashtable_search_key.c
HASHTABLE	+=	$(HASHPATH)hashtable_keys.c
HASHTABLE	+=	$(HASHPATH)hashtable_values.c

SOURCES		=	$(LIST)
SOURCES		+=	$(HASHTABLE)
SOURCES		+=	$(STRING)

OBJECTS		=	$(patsubst %.c, $(BUILD)/$(DOBJECTS)%.o, $(SOURCES))

DEPS		=	$(patsubst %.c, $(BUILD)/$(DOBJECTS)%.d, $(SOURCES))

DEPENDS		=	-MT $@ -MD -MP -MF $(subst .o,.d,$@)

all: $(BUILD)/$(NAME)

$(BUILD)/$(NAME): $(OBJECTS)
	@echo "\n\033[0;32m$(NAME) compiled:\t\033[0;m\c"
	ar rcs $(BUILD)/$(NAME) $(OBJECTS)

-include $(OBJECTS:.o=.d)

$(BUILD)/$(DOBJECTS)%.o: $(DSOURCES)%.c
	@mkdir -p $(BUILD)/$(DOBJECTS)$(LISTPATH)
	@mkdir -p $(BUILD)/$(DOBJECTS)$(HASHPATH)
	@mkdir -p $(BUILD)/$(DOBJECTS)$(STRINGPATH)
	@echo "\033[0;32m$< compiled:\t\033[0;m\c"
	$(CC) $(CFLAGS) $(DEPENDS) -o $@ -c $< $(INCLUDES)

clean:
	@rm -rf $(BUILD)/$(DOBJECTS)

fclean: clean
	@rm -f $(BUILD)/$(NAME)
	@rm -rf $(BUILD)

re: fclean all

.PHONY: all clean fclean re
