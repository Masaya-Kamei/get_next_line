# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 18:28:14 by mkamei            #+#    #+#              #
#    Updated: 2021/10/29 18:27:25 by mkamei           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCSNAME:=	unit_tests/main.c get_next_line.c get_next_line_utils.c
SRCSDIR	:=	../
SRCS	:=	$(addprefix $(SRCSDIR)/, $(SRCSNAME))

OBJSNAME:=	$(SRCSNAME:.c=.o)
OBJSDIR	:=	./objs
OBJS	:=	$(addprefix $(OBJSDIR)/, $(OBJSNAME))

INCLUDE	:=	-I./ -I../
NAME	:=	gnl

CC		:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror
RM		:=	rm -rf

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -o $@

$(OBJSDIR)/%.o	:	$(SRCSDIR)/%.c
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

clean	:
			$(RM) $(OBJS)

fclean	: 	clean
			$(RM) $(NAME)

re		:	fclean all

# Use llvm clang
# For Macos, https://stackoverflow.com/questions/53456304/mac-os-leaks-sanitizer

address	:	CC			=	clang
address	:	CFLAGS 		+= 	-g -fsanitize=address
address	:	re

leak	:	CC			=	clang
leak	:	CFLAGS 		+= 	-g -fsanitize=leak
leak	:	re

.PHONY	:	all clean fclean re address leak
