##
## Makefile for  in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
## 
## Made by Eric DESCHODT
## Login   <descho_e@epitech.net>
## 
## Started on  Mon Mar  7 13:18:01 2016 Eric DESCHODT
## Last update Fri Mar 18 16:28:31 2016 Eric DESCHODT
##

NAME		=		../../corewar

SRC		=		main.c			\
				start_vm.c		\
				utils.c			\
				op.c			\
				living.c		\
				load_instru.c		\
				zjump.c			\
				sti.c			\
				ld.c

OBJ		=		$(SRC:.c=.o)

CFLAGS		+=		-W -Wall -Wextra -ansi -pedantic
#CFLAGS		+=		-Werror
CFLAGS		+=		-g3
CFLAGS		+=		-I../../include

LFLAGS		=		-lmyprintf -L../../lib

all		:		$(NAME)

$(NAME)		:		$(OBJ)
				cc -o $(NAME) $(OBJ) $(LFLAGS)

clean		:
				rm -rf $(OBJ)

fclean		:		clean
				rm -rf $(NAME)

re		:		fclean all

.PHONY		:		all clean fclean re
