#*****************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abureau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/04 12:47:45 by abureau           #+#    #+#              #
#    Updated: 2016/04/21 11:23:20 by abureau          ###   ########.fr        #
#                                                                              #
#******************************************************************************#



NAME = test_gnl

DIRSRC = ./includes/

SRC = ./get_next_line.c \

CC = gcc

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g

all:$(NAME)

$(NAME): $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -I libft/includes -o $@ -c $<

fclean:
	rm -f get_next_line.o

re: fclean all


