/*
** syntaxe4.c for syntace4.c in /home/roig_a/COREWAR/coreware/corewar/src
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Thu Mar 24 19:00:33 2016 Antoine Roig
** Last update Fri Mar 25 22:00:24 2016 Eric DESCHODT
*/

#include "corewar.h"

int	is_nbr_dump(char *str)
{
  int   i;

  i = 0;

  while (str[i])
    {
      if (str[i] >= 48 && str[i] <= 57)
        i++;
      else
	{
	  my_putstr("Please enter a positiv number\n");
	  exit(0);
	}
    }
  return (0);
}

void	init_var(t_var *var)
{
  var->a = 0;
  var->n = 0;
  var->d = 0;
}
