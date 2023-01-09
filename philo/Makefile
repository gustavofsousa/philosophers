# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 18:38:35 by gusousa           #+#    #+#              #
#    Updated: 2023/01/09 11:56:17 by gusousa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= philo
MAKEFLAGS	:= --silent

######	Compiler #####
CC	:= cc
CFLAGS	:= c -Wextra -Werror -Wall -pthreads -g

######	Compiler #####
SRCDIR	:= source/
OBJDIR	:= obj/
INCDIR	:= include/

######	Compiler #####
SRC	:=	main.c							\
		common.c utils.c print_color.c	\
		init.c

OBJ	:= $(addprefix $(OBJDIR), $(SRC:.c=.o))

######	Compiler #####

all: obj $(NAME)

obj:
	mkdir -p $(OBJDIR)

clean:
	rm -rf obj/

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re, fclean, clean
