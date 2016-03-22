##
## Makefile for  in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
## 
## Made by Eric DESCHODT
## Login   <descho_e@epitech.net>
## 
## Started on  Mon Mar  7 13:18:01 2016 Eric DESCHODT
<<<<<<< HEAD
## Last update Tue Mar 22 13:38:21 2016 Antoine Roig
=======
## Last update Tue Mar 22 08:55:11 2016 Eric DESCHODT
>>>>>>> f78e1cebe5038699e42c3181abc41648e55b1f3f
##

NAME		=		../../corewar

SRC		=		main.c			\
				start_vm.c		\
				utils.c			\
				op.c			\
				living.c		\
				load_instru.c		\
				parsing.c		\
				utils_list.c		\
				list_champ.c		\
				pop_list.c		\
				add_list.c		\
				zjump.c			\
				sti.c			\
				add.c			\
				or.c			\
				xor.c			\
				and.c			\
				sub.c			\
				ld.c			\
				forking.c		\
				create_champ.c		\
				movingPC.c

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
