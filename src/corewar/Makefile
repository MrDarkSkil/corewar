##
## Makefile for  in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
## 
## Made by Eric DESCHODT
## Login   <descho_e@epitech.net>
## 
## Started on  Mon Mar  7 13:18:01 2016 Eric DESCHODT
## Last update Mon Mar  7 14:04:51 2016 Eric DESCHODT
##

NAME		=		../../corewar

SRC		=		main.c		\
				start_vm.c

OBJ		=		$(SRC:.c=.o)

CFLAGS		+=		-W -Wall -Wextra -ansi -pedantic
#CFLAGS		+=		-Werror
#CFLAGS		+=		-g3
CFLAGS		+=		-I../../include

all		:		$(NAME)

$(NAME)		:		$(OBJ)
				cc -o $(NAME) $(OBJ)

clean		:
				rm -rf $(OBJ)

fclean		:		clean
				rm -rf $(NAME)

re		:		fclean all

.PHONY		:		all clean fclean re
