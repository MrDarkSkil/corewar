/*
** syntax3.c for syntax3.c in /home/roig_a/COREWAR/coreware
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Thu Mar 24 00:23:38 2016 Antoine Roig
** Last update Thu Mar 24 00:24:22 2016 Antoine Roig
*/

#include "corewar.h"

int	check_para(t_dlist *list)
{
  t_list	*tmp;

  tmp = list->begin;
  while (tmp)
    {
      if (is_nbr(tmp->arg) == 0)
	if (tmp == list->begin || (my_strcmp(tmp->prev->arg, "-dump") != 0 &&
				   my_strcmp(tmp->prev->arg, "-a") != 0 &&
				   my_strcmp(tmp->prev->arg, "-n") != 0))
	  exit(0);
      tmp = tmp->next;
    }
  return (0);
}
