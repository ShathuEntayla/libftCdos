# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhidalgo <fhidalgo@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/06 12:02:17 by fhidalgo          #+#    #+#              #
#    Updated: 2026/10/10 21:33:42 by fhidalgo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

DIR_S = ./
SOURCES = \
	$(DIR_S)ft_strrchr.c\
	$(DIR_S)ft_strlen.c\
	
OBJS = $(SOURCES:.c=.o)
INCLUDES = libft.h

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

#COMANDOS ADICIONALES#

re_s: re
	cc ft_strrchr.c libft.a
	./a.out

nc:
	norminette *.c

nl: 
	norminette libft.h

g:
	git add .
	-git commit -m "Añadimos funciones - $$(date +%H:%M:%S)"
	git push
	git status
	git log -1 --oneline

gr:
	git push
	git status
	git log -1 --oneline
