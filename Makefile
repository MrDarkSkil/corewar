##
## Makefile for  in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
## 
## Made by Eric DESCHODT
## Login   <descho_e@epitech.net>
## 
## Started on  Mon Mar  7 13:27:34 2016 Eric DESCHODT
## Last update Mon Mar  7 14:26:44 2016 Eric DESCHODT
##

MAKE	=	make --no-print-directory

all	:
		@$(MAKE) all -C lib/my
		@$(MAKE) all -C src/corewar/

clean	:
		@$(MAKE) clean -C lib/my
		@$(MAKE) clean -C src/corewar/

fclean	:	clean
		@$(MAKE) fclean -C lib/my
		@$(MAKE) fclean -C src/corewar/

re	:	fclean all

.PHONY	:	all clean fclean re
