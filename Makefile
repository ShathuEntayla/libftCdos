# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhidalgo <fhidalgo@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/06 12:02:17 by fhidalgo          #+#    #+#              #
#    Updated: 2026/10/24 02:58:19 by fhidalgo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

DIR_S = ./
SOURCES = \
	$(DIR_S)ft_isalpha.c\
	$(DIR_S)ft_isdigit.c\
	$(DIR_S)ft_isalnum.c\
	$(DIR_S)ft_isascii.c\
	$(DIR_S)ft_isprint.c\
    $(DIR_S)ft_strlen.c\
	$(DIR_S)ft_memset.c\
    $(DIR_S)ft_bzero.c\
    $(DIR_S)ft_memcpy.c\
    $(DIR_S)ft_memmove.c\
    $(DIR_S)ft_strlcpy.c\
    $(DIR_S)ft_strlcat.c\
	$(DIR_S)ft_toupper.c\
	$(DIR_S)ft_tolower.c\
    $(DIR_S)ft_strchr.c\
    $(DIR_S)ft_strrchr.c\
	$(DIR_S)ft_strncmp.c\
	$(DIR_S)ft_memchr.c\
	$(DIR_S)ft_memcmp.c\
	$(DIR_S)ft_strnstr.c\
	$(DIR_S)ft_atoi.c\
	$(DIR_S)ft_calloc.c\
	$(DIR_S)ft_strdup.c\
	$(DIR_S)ft_substr.c\
	$(DIR_S)ft_strjoin.c\
	$(DIR_S)ft_strtrim.c\
	$(DIR_S)ft_split.c\
	$(DIR_S)ft_striteri.c\
	$(DIR_S)ft_putchar_fd.c\
	$(DIR_S)ft_putstr_fd.c\
	$(DIR_S)ft_putendl_fd.c\
	$(DIR_S)ft_putnbr_fd.c\
	$(DIR_S)ft_lstadd_front.c\
	$(DIR_S)ft_lstnew.c\
	$(DIR_S)ft_lstsize.c\
	$(DIR_S)ft_lstlast.c\
	$(DIR_S)ft_lstadd_back.c\
	$(DIR_S)ft_lstdelone.c\
	$(DIR_S)ft_lstclear.c\
	$(DIR_S)ft_itoa.c\
	$(DIR_S)ft_strmapi.c\
	$(DIR_S)ft_lstiter.c\
	$(DIR_S)ft_lstmap.c\

OBJS = $(SOURCES:.c=.o)

INCLUDES = libft.h

CC = cc
MEM_CHECK = valgrind
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES)

all: $(NAME)

bonus: all

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

#COMANDOS ADICIONALES#

TESTABLE = \
	$(DIR_S)ft_itoa.c\
	$(DIR_S)ft_calloc.c\

TEST = $(TESTABLE:.c=.o)

re_s: $(TEST)
	@ar rcs libft.a $(TEST)
	@cc ft_memcpy.c libft.a
	@echo ""
	./a.out	
	@echo ""
	@echo ""
	@make fclean

nc:
	norminette *.c

nl: 
	norminette libft.h

g:
	git add .
	git commit -m "Correciones de última hora - $$(date +%H:%M:%S)"
	git push
	git status
	git log -1 --oneline

gls:
	git ls-files