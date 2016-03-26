##
## Makefile for asm in /home/julian_r/rendu/prog_elem/coreware/src/asm
## 
## Made by Juliani Renaud
## Login   <julian_r@epitech.net>
## 
## Started on  Tue Mar  8 14:27:46 2016 Juliani Renaud
## Last update Fri Mar 25 19:25:55 2016 Léo Hubert
##

NAME	=	asm

SRC	=	src/main.c					\
		src/op.c					\
		src/header/header.c				\
		src/header/parse_header.c			\
		src/my_utils/str_to_wordtab.c			\
		src/my_utils/utils.c				\
		src/my_utils/file_my.c				\
		src/my_utils/linked_list.c			\
		src/my_utils/my_takestr.c			\
		src/my_utils/my_strcmp.c			\
		src/prepare_asm/write_instructions.c		\
		src/prepare_asm/utils_check.c			\
		src/prepare_asm/parsing.c			\
		src/prepare_asm/params_1.c			\
		src/prepare_asm/params_2.c			\
		src/prepare_asm/params_3.c			\
		src/prepare_asm/params_4.c			\
		src/prepare_asm/check_params.c			\
		src/write_asm/instructions_file.c		\
		src/write_asm/ld.c				\
		src/write_asm/sti.c				\
		src/write_asm/ldi.c				\
		src/write_asm/living.c				\
		src/error/error.c				\
		../lib/get_next_line/get_next_line.c

OBJ	=	$(SRC:.c=.o)

CFLAGS  +=	-Werror
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
