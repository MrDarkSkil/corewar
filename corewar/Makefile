##
## Makefile for  in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
## 
## Made by Eric DESCHODT
## Login   <descho_e@epitech.net>
## 
## Started on  Mon Mar  7 13:18:01 2016 Eric DESCHODT
## Last update Wed Mar 23 21:53:42 2016 Antoine Roig
##

NAME		=		corewar

SRC		=		src/main.c		\
				src/start_vm.c		\
				src/utils.c		\
				src/op.c		\
				src/living.c		\
				src/load_instru.c	\
				src/parsing.c		\
				src/parsing2.c		\
				src/utils_list.c	\
				src/list_champ.c	\
				src/list_champ2.c	\
				src/pop_list.c		\
				src/add_list.c		\
				src/kill_champ.c	\
				src/zjump.c		\
				src/sti.c		\
				src/syntax.c		\
				src/add.c		\
				src/ldi.c		\
				src/lldi.c		\
				src/or.c		\
				src/xor.c		\
				src/and.c		\
				src/sub.c		\
				src/ld.c		\
				src/forking.c		\
				src/create_champ.c	\
				src/movingPC.c		\
				src/info_champ.c

OBJ		=		$(SRC:.c=.o)

CFLAGS		+=		-W -Wall -Wextra -ansi -pedantic
CFLAGS		+=		-Werror
CFLAGS		+=		-I../include

LFLAGS		=		-lmy -L../lib

all		:		$(NAME)

$(NAME)		:		$(OBJ)
				cc -o $(NAME) $(OBJ) $(LFLAGS)

clean		:
				rm -rf $(OBJ)

fclean		:		clean
				rm -rf $(NAME)

re		:		fclean all

.PHONY		:		all clean fclean re
