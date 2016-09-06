#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/09 13:23:47 by niccheva          #+#    #+#              #
#    Updated: 2016/09/06 11:31:36 by niccheva         ###   ########.fr        #
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

LIST		=	init_list.c
LIST		+=	list_add.c
LIST		+=	list_add_tail.c
LIST		+=	list_del.c
LIST		+=	list_del_init.c
LIST		+=	list_empty.c
LIST		+=	list_is_last.c
LIST		+=	list_is_singular.c
LIST		+=	list_size.c
LIST		+=	private_list_add.c
LIST		+=	private_list_del.c
LIST		+=	private_list_del_entry.c

HASHTABLE	=	hashtable_create_from_tab.c
HASHTABLE	+=	hashtable_create_to_tab.c
HASHTABLE	+=	hashtable_display.c
HASHTABLE	+=	hashtable_delete.c
HASHTABLE	+=	hashtable_delete_entry.c
HASHTABLE	+=	hashtable_new_elem.c
HASHTABLE	+=	hashtable_modify_elem.c
HASHTABLE	+=	hashtable_search_key.c
HASHTABLE	+=	hashtable_keys.c
HASHTABLE	+=	hashtable_values.c

SOURCES		=	$(LIST)
SOURCES		+=	$(HASHTABLE)

OBJECTS		=	$(patsubst %.c, $(BUILD)/$(DOBJECTS)%.o, $(SOURCES))

DEPS		=	$(patsubst %.c, $(BUILD)/$(DOBJECTS)%.d, $(SOURCES))

DEPENDS		=	-MT $@ -MD -MP -MF $(subst .o,.d,$@)

all: $(BUILD)/$(NAME)

$(BUILD)/$(NAME): $(OBJECTS)
	@echo "\n\033[0;32m$(NAME) compiled:\t\033[0;m\c"
	ar rcs $(BUILD)/$(NAME) $(OBJECTS)

-include $(OBJECTS:.o=.d)

$(BUILD)/$(DOBJECTS)%.o: $(DSOURCES)%.c
	@mkdir -p $(BUILD)/$(DOBJECTS)
	@echo "\033[0;32m$< compiled:\t\033[0;m\c"
	$(CC) $(CFLAGS) $(DEPENDS) -o $@ -c $< $(INCLUDES)

clean:
	@rm -rf $(BUILD)/$(DOBJECTS)

fclean: clean
	@rm -f $(BUILD)/$(NAME)
	@rm -rf $(BUILD)

re: fclean all

.PHONY: all clean fclean re
