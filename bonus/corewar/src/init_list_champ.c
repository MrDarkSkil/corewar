/*
** init_list_champ.c for init_list_champ in /home/roig_a/Corewar/coreware
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Mon Mar  7 15:54:12 2016 Antoine Roig
** Last update Fri Mar 25 21:45:45 2016 Eric DESCHODT
*/

#include "corewar.h"

t_vm	*new_vm(t_vm *vm)
{
  vm = xmalloc(sizeof(*vm));
  vm->begin = NULL;
  vm->end = vm->begin;
  vm->nb = 0;
  return (vm);
}

t_champlist	*new_champ(t_champlist *champ,
			   int id,
			   int cycle)
{
  champ = xmalloc(sizeof(*champ));
  champ->end = champ->begin;
  champ->id = id;
  champ->next = NULL;
  champ->begin = xmalloc(sizeof(t_instru));
  champ->current = champ->begin;
  champ->begin->ope.comment = "yo";
  champ->begin->ope.nbr_cycles = cycle;
  champ->begin->current_cycle = 0;
  champ->begin->next = champ->begin;
  return (champ);
}

void	add_champ_vm(t_vm *vm,
		     t_champlist *champ,
		     int nb_champ,
		     int cycle)
{
  champ = new_champ(champ, nb_champ, cycle);
  if (vm->begin == NULL)
    {
      vm->begin = champ;
      vm->end = champ;
      vm->nb = 1;
    }
  else
    {
      champ->next = vm->begin;
      vm->begin->prev = champ;
      vm->begin = champ;
      vm->nb = vm->nb + 1;
    }
}

void	launch_vm(t_vm *vm, int nb_champ)
{
  int		i;
  t_champlist	*champ;
  int		cycle;

  cycle = 2;
  i = 0;
  while (i < nb_champ)
    {
      champ = NULL;
      add_champ_vm(vm, champ, i, cycle);
      cycle *= 2;
      i++;
    }
}
