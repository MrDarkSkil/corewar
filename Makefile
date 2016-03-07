##
## Makefile for  in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
## 
## Made by Eric DESCHODT
## Login   <descho_e@epitech.net>
## 
## Started on  Mon Mar  7 13:27:34 2016 Eric DESCHODT
## Last update Mon Mar  7 13:28:46 2016 Eric DESCHODT
##

all	:
		make all -C src/corewar/

clean	:
		make clean -C src/corewar/

fclean	:	clean
		make fclean -C src/corewar/

re	:	fclean all

.PHONY	:	all clean fclean re
