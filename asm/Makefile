##
## Makefile for asm in /home/julian_r/rendu/prog_elem/coreware/src/asm
## 
## Made by Juliani Renaud
## Login   <julian_r@epitech.net>
## 
## Started on  Tue Mar  8 14:27:46 2016 Juliani Renaud
## Last update Fri Mar 25 16:31:26 2016 Léo Hubert
##

NAME	=	asm

SRC	=	src/main.c				\
		src/file_my.c				\
		src/parse_header.c			\
		src/write_instructions.c		\
		src/error.c				\
		src/utils.c				\
		src/instructions_file.c			\
		src/header.c				\
		src/str_to_wordtab.c			\
		src/linked_list.c			\
		src/my_takestr.c			\
		src/my_strcmp.c				\
		src/op.c				\
		src/ld.c				\
		src/sti.c				\
		src/ldi.c				\
		src/living.c				\
		../lib/get_next_line/get_next_line.c

OBJ	=	$(SRC:.c=.o)

#CFLAGS  +=	-Werror
CFLAGS	+=	-Wextra -Wall
CFLAGS	+=	-pedantic -ansi
CFLAGS	+=	-I../include

LFLAGS          =               -lmy -L../lib


CC	=	gcc

RM	=	rm -rf

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LFLAGS)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
