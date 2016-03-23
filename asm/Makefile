##
## Makefile for asm in /home/julian_r/rendu/prog_elem/coreware/src/asm
## 
## Made by Juliani Renaud
## Login   <julian_r@epitech.net>
## 
## Started on  Tue Mar  8 14:27:46 2016 Juliani Renaud
## Last update Wed Mar 23 12:02:54 2016 Eric DESCHODT
##

NAME	=	asm

SRC	=	src/main.c				\
		src/file_my.c				\
		src/parse_header.c			\
		src/header.c				\
		src/my_takestr.c			\
		src/my_strcmp.c				\
		../lib/get_next_line/get_next_line.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-Werror -Wextra -Wall
CFLAGS	+=	-pedantic -ansi
CFLAGS	+=	-I../include
CFLAGS	+=	-lmy -l../lib

CC	=	gcc

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
