##
## Makefile for asm in /home/julian_r/rendu/prog_elem/coreware/src/asm
## 
## Made by Juliani Renaud
## Login   <julian_r@epitech.net>
## 
## Started on  Tue Mar  8 14:27:46 2016 Juliani Renaud
## Last update Tue Mar  8 14:27:50 2016 Juliani Renaud
##

NAME	=	asm

SRC	=	

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-Werror -Wextra -Wall
CFLAGS	+=	-pedantic -ansi
CFLAGS	+=	-I./include

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
