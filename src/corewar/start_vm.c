/*
** start_vm.c for corewar in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Mar  7 13:35:33 2016 Eric DESCHODT
** Last update Mon Mar 14 13:47:29 2016 Eric DESCHODT
*/

#include "corewar.h"

void		init_alive(t_vm *vm)
{
  int		i;
  t_champ	*tmp;

  tmp = vm->begin;
  i = 0;
  while (i < vm->nb)
    {
      tmp->alive = 0;
      tmp = tmp->next;
      i++;
    }
}

void		load_instru(t_champ *champ,
			    unsigned char *board)
{
  (void)board;
  champ->ope.nbr_cycles = 1;
}

int		execute_champ(t_champ *champ,
			      unsigned char *board)
{
  if (champ->cycle == 0)
    load_instru(champ, board);
  else if (champ->cycle == champ->ope.nbr_cycles)
    {
      champ->instru += 1;
      champ->cycle = 0;
      champ->cursor += 1;
    }
  my_printf("%x\n", *champ->instru);
  champ->cycle++;
  if (champ->cursor == (champ->size))
    {
      my_printf("==== RESET ====\n");
      champ->instru -= (champ->size + 1);
      champ->cursor = -1;
    }
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
      execute_champ(tmp, board);
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
