/*
** my_memset.c for  in /home/descho_e/year_2015_2016/C_Prog_Elem/CPE_2015_corewar
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Wed Mar 23 12:35:18 2016 Eric DESCHODT
** Last update Wed Mar 23 12:35:20 2016 Eric DESCHODT
*/

#include "my.h"

void		my_memset(char *str,
			  int size,
			  char c)
{
  int		i;

  i = 0;
  while (i < size)
    {
      str[i] = c;
      i++;
    }
}
