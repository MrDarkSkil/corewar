/*
** check_id.c for check_id.c in /home/roig_a/COREWAR/CPE_2015_corewar
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Fri Mar 25 18:14:46 2016 Antoine Roig
** Last update Fri Mar 25 21:42:25 2016 Eric DESCHODT
*/

#include "corewar.h"

void		check_multiple_id(t_vm *vm)
{
  int		i;
  int		c;
  t_champ	*tmp;

  tmp = vm->begin;
  i = 1;
  while (i < 5)
    {
      c = 0;
      while (tmp)
	{
	  if (tmp->id == i)
	    c++;
	  tmp = tmp->next;
	}
      if (c > 1)
	{
	  my_putstr("Multiple definition of id : ");
	  my_putchar(i + 48);
	  write(1, "\n", 1);
	  exit(EXIT_FAILURE);
	}
      i++;
    }
}
