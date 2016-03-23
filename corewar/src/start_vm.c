/*
** start_vm.c for corewar in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Mar  7 13:35:33 2016 Eric DESCHODT
** Last update Wed Mar 23 13:32:14 2016 Eric DESCHODT
*/

#include "corewar.h"

void            init_alive(t_vm *vm)
{
  int           i;
  t_champ       *tmp;

  tmp = vm->begin;
  i = 0;
  while (i < vm->nb)
    {
      tmp->alive = 0;
      tmp = tmp->next;
      i++;
    }
}

int		execute_champ(t_vm *vm, t_champ *champ,
			      unsigned char *board)
{
  if (champ->cycle == 0)
    load_instru(vm, champ, board);
  if (champ->cycle == champ->ope.nbr_cycles)
    champ->cycle = 0;
  else
    champ->cycle++;
  return (0);
}

int		all_champ(t_vm *vm,
			  unsigned char *board)
{
  int		i;
  t_champ	*tmp;

  i = 0;
  tmp = vm->begin;
  while (i < vm->nb)
    {
      execute_champ(vm, tmp, board);
      tmp = tmp->next;
      i++;
    }
  return (0);
}

int		start_vm(t_vm *vm,
			 unsigned char *board)
{
  int		end;
  int		start;
    
  end = CYCLE_TO_DIE;
  while (end > 0)
    {
      start = end;
      init_alive(vm);
      while (start > 0)
	{
	  all_champ(vm, board);
	  start--;
	}
      end -= CYCLE_DELTA;
    }
  return (0);
}
