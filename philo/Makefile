# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 18:38:35 by gusousa           #+#    #+#              #
#    Updated: 2023/01/19 15:44:37 by gusousa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= philo
MAKEFLAGS	:= --silent

######	Compiler #####
CC		:= cc
CFLAGS	:= -Wextra -Werror -Wall -g

######	Directories #####
SRCDIR	:= source/
OBJDIR	:= obj/
INCDIR	:= include/

######	Source & objects #####
SRC	:=	main.c							\
		common.c utils.c print_color.c	\
		init.c quit.c						\
		routine.c actions.c monitor.c

OBJ	:= $(addprefix $(OBJDIR), $(SRC:.c=.o))

######	Rules #####

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lpthread -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o : $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf obj/

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re, fclean, clean, all, obj
