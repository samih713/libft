# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 16:31:07 by sabdelra          #+#    #+#              #
#    Updated: 2022/11/30 16:31:08 by sabdelra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

ROOT:= libft_malloc
NAME:= $(ROOT)_$(HOSTTYPE).a
DNAME:= $(ROOT)_$(HOSTTYPE)dyn.dylib

RM:= rm -rf
AR:= ar -rcs

INCLUDES_DIR:= includes/
INCLUDES:= libft.h

CC:= cc
CFLAGS:= -Wall -Werror -Wextra -I$(INCLUDES_DIR)

SRCS_DIR:= srcs/
SRCS:= $(wildcard $(SRCS_DIR)*.c)

OBJS_DIR := objs/
OBJS:= $(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

all : $(NAME)

dynamic: CFLAGS += -fPIC
dynamic: $(DNAME)

test_dynamic: $(DNAME)
	$(CC) -L. -lft_malloc_x86_64_Darwindyn -ldl main.c -o dynamic  

$(DNAME): $(OBJS)
	$(CC) $(CFLAGS) -dynamiclib -o $@ $^

$(NAME) : $(OBJS)
	$(AR) $@ $^

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIR)
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJS_DIR):
	mkdir $@

fclean : clean clean_test
	$(RM) $(NAME)
	$(RM) $(DNAME)

clean_test :
	$(RM) static
	$(RM) dynamic

clean :
	$(RM) $(OBJS)
	$(RM) $(OBJS_DIR)

re :
	$(MAKE) fclean
	$(MAKE)

.PHONY: all bonus clean fclean re dynamic clean_test

