##
## Makefile for  in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
## 
## Made by Eric DESCHODT
## Login   <descho_e@epitech.net>
## 
## Started on  Mon Mar  7 14:19:42 2016 Eric DESCHODT
## Last update Mon Mar  7 15:09:57 2016 Eric DESCHODT
##

NAME	=	../libmyprintf.a

CFLAGS  +=      -W -Wextra -Wall
CFLAGS  +=      -ansi -pedantic
CFLAGS  +=      -I../../include
CFLAGS  +=      -Werror

SRC	=	my_putchar.c \
                noflags.c \
                my_getnbr.c \
                my_revstr.c \
                my_putstr.c \
                my_put_nbr.c \
                my_put_float.c \
                convert_base.c \
                my_strlen.c \
                my_getnbr_base.c \
                my_showstr.c \
                my_memset.c \
                my_printf.c \
                my_printf_flags.c \
                my_printf_ope.c \
                my_printf_ope2.c \
                int_in_str.c \
                my_put_nbr_base.c

OBJ	=	$(SRC:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
