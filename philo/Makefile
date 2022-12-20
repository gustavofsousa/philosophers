# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 18:38:35 by gusousa           #+#    #+#              #
#    Updated: 2022/12/13 18:38:45 by gusousa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= philo
MAKEFLAGS	:= --silent

######	Compiler #####
CC	:= cc
CFLAGS	:= c -jextra -Werror -Wall -pthreads -g

######	Compiler #####
SRCDIR	:= source/
OBJDIR	:= obj/
INCDIR	:= include/

######	Compiler #####
SRC	:= main.c

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

i.PHONY: re, fclean, clean
