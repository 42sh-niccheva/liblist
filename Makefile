#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/09 13:23:47 by niccheva          #+#    #+#              #
#    Updated: 2016/07/11 13:39:26 by llapillo         ###   ########.fr        #
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

SOURCES		=	init_list.c
SOURCES		+=	list_add.c
SOURCES		+=	list_add_tail.c
SOURCES		+=	list_del.c
SOURCES		+=	list_del_init.c
SOURCES		+=	list_empty.c
SOURCES		+=	list_is_last.c
SOURCES		+=	list_is_singular.c
SOURCES		+=	private_list_add.c
SOURCES		+=	private_list_del.c
SOURCES		+=	private_list_del_entry.c
SOURCES		+=	hashtable_create_from_tab.c
SOURCES		+=	hashtable_create_to_tab.c
SOURCES		+=	hashtable_display.c
SOURCES		+=	hashtable_delete.c
SOURCES		+=	hashtable_delete_entry.c
SOURCES		+=	hashtable_new_elem.c
SOURCES		+=	hashtable_modify_elem.c

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
