##
## Makefile for  in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
## 
## Made by Eric DESCHODT
## Login   <descho_e@epitech.net>
## 
## Started on  Mon Mar  7 13:27:34 2016 Eric DESCHODT
## Last update Wed Mar 23 11:57:47 2016 Eric DESCHODT
##

MAKE	=	make --no-print-directory

all	:
		@$(MAKE) all -C lib/my
		@$(MAKE) all -C corewar/
		@$(MAKE) all -C asm/

clean	:
		@$(MAKE) clean -C lib/my
		@$(MAKE) clean -C corewar/
		@$(MAKE) clean -C asm/

fclean	:	clean
		@$(MAKE) fclean -C lib/my
		@$(MAKE) fclean -C corewar/
		@$(MAKE) fclean -C asm/

re	:	fclean all

.PHONY	:	all clean fclean re
