/*
** start_vm.c for corewar in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Mar  7 13:35:33 2016 Eric DESCHODT
** Last update Mon Mar  7 14:00:44 2016 Eric DESCHODT
*/

#include "corewar.h"

void		exec_champ(t_champlist *champ)
{
  t_instru	*cur_instru;

  cur_instru = champ->begin;
  if (cur_instru.current_cycle == 0)
    printf("%d : %s\n", champ->id, cur_instru.ope.mnemonique);
  cur_instru.current_cycle++;
  if (cur_instru.current_cycle == cur_instru.ope.nbr_cycles)
    {
      cur_instru.current_cycle = 0;
      champ->begin = champ->begin->next;
    }
}

int		start_vm(t_vm *vm)
{
  t_champlist	*cur_champ;
  int		cycle;
  int		i;

  cycle = CYCLE_TO_DIE;
  while (cycle > 0)
    {
      i = 0;
      cur_champ = vm->begin;
      while (i < 4)
	{
	  exec_champ(cur_champ);
	  cur_champ = cur_champ->next;
	  i++;
	}
      cycle -= CYCLE_DELTA;
    }
}
