/*
** load_add.c for load_add.c in /home/roig_a/COREWAR/coreware
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Thu Mar 24 02:30:48 2016 Antoine Roig
** Last update Thu Mar 24 02:31:04 2016 Antoine Roig
*/

#include "corewar.h"

void	basic_start(t_vm *vm)
{
  t_champion	*tmp;

  tmp = vm->begin;
  if (tmp)
    {
      tmp->cursor = MEM_SIZE * 0;
      tmp = tmp->next;
    }
    return;
  if (tmp)
    {
      tmp->cursor = MEM_SIZE / 2;
      tmp = tmp->next;
    }
  if (tmp)
    {
      tmp->cursor = MEM_SIZE / 4;
      tmp = tmp->next;
    }
  if (tmp)
    {
      tmp->cursor = MEM_SIZE - (MEM_SIZE / 4);
      tmp = tmp->next;
    }
  return;
}
