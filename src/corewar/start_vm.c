/*
** start_vm.c for corewar in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Mar  7 13:35:33 2016 Eric DESCHODT
** Last update Mon Mar  7 13:44:23 2016 Eric DESCHODT
*/

#include "corewar.h"

void		exec_champ(t_champ *champ)
{
  t_instru	*cur_instru;

  cur_instru = champ->list;
  if (cur_instru.current_cycle == 0)
    {
      my_putstr(cu
    }
}

int		start_vm(t_vm *vm)
{
  t_champ	*cur_champ;
  int		i;

  while (42)
    {
      i = 0;
      cur_champ = vm->list;
      while (i < 4)
	{
	  exec_champ(cur_champ);
	  cur_champ = cur_champ->next;
	  i++;
	}
    }
}
