# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 18:38:35 by gusousa           #+#    #+#              #
#    Updated: 2023/01/10 15:11:55 by gusousa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= philo
MAKEFLAGS	:= --silent

######	Compiler #####
CC		:= cc
CFLAGS	:= -Wextra -Werror -Wall -g

######	Compiler #####
SRCDIR	:= source/
OBJDIR	:= obj/
INCDIR	:= include/

######	Compiler #####
SRC	:=	main.c							\
		common.c utils.c print_color.c	\
		init.c							\
		routine.c actions.c

OBJ	:= $(addprefix $(OBJDIR), $(SRC:.c=.o))

######	Compiler #####

all: obj $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $@

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o : $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf obj/

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re, fclean, clean, all, obj
