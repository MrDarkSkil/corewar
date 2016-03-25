##
## Makefile for  in /home/descho_e/year_2015_2016/I_graph/tekadventure
## 
## Made by Eric DESCHODT
## Login   <descho_e@epitech.net>
## 
## Started on  Sun Jan 31 13:59:32 2016 Eric DESCHODT
## Last update Mon Feb 29 09:46:17 2016 Eric DESCHODT
##

NAME		=	../libgraph.a

CC		=	gcc

LIB		=	-L/home/${USER}/.froot/lib/ -llapin 	\
			-L/usr/local/lib 			\
			-lsfml-audio 				\
			-lsfml-graphics 			\
			-lsfml-window 				\
			-lsfml-system 				\
			-lstdc++ -ldl 				\
			-lm -rdynamic

CFLAGS		=	-W -Wall -Wextra			\
			-I/home/${USER}/.froot/include/		\
			-I../include

SRC		=	binarizer.c				\
			fill.c					\
			get_chmp.c				\
			tekpixel.c

SRC		+=	my_getnbr_base.c			\
			my_getnbr.c				\
			my_strcpy.c				\
			my_strlen.c


OBJ		=	$(SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJ)
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)

clean:
			rm -f $(OBJ)

fclean:			clean
			rm -f $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
