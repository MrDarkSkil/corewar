##
## Makefile for asm in /home/julian_r/rendu/prog_elem/coreware/src/asm
## 
## Made by Juliani Renaud
## Login   <julian_r@epitech.net>
## 
## Started on  Tue Mar  8 14:27:46 2016 Juliani Renaud
## Last update Sun Mar 20 23:36:11 2016 Léo Hubert
##

NAME	=	./../../asm

SRC	=	main.c					\
		file_my.c				\
		parse_header.c				\
		my_takestr.c				\
		my_strcmp.c				\
		../../lib/get_next_line/get_next_line.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-Werror -Wextra -Wall
CFLAGS	+=	-pedantic -ansi
CFLAGS	+=	-I./../../include
CFLAGS	+=	-lmyprintf -l./../../lib

CC	=	gcc -g3

RM	=	rm -rf

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
