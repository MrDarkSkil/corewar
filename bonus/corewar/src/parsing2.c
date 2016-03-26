/*
** parsin2.c for parsing2.c in /home/roig_a/COREWAR/coreware/corewar/src
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Wed Mar 23 13:26:45 2016 Antoine Roig
** Last update Fri Mar 25 13:12:37 2016 Antoine Roig
*/

#include "corewar.h"

t_list	*parsing2(t_list *tmp, int *j)
{
  tmp = tmp->next;
  (*j)++;
  return (tmp);
}

void	fill_info(t_lcmd *info, char *name)
{
  info->id = 0;
  info->a = 0;
  info->name = name;
}

t_list		*inifind(t_dlist *list, int *j)
{
  *j = 0;
  return (list->begin);
}
