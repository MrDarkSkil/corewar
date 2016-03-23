/*
** list_champ.c for list_champ.c in /home/roig_a/coreware/coreware
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Fri Mar 18 18:34:50 2016 Antoine Roig
** Last update Wed Mar 23 10:48:38 2016 Antoine Roig
*/

#include "corewar.h"

void	fill_new(t_champ *new, t_champ *champ)
{
  new->instru = champ->instru;
  new->start = champ->start;
  new->cycle =  1;
  new->cursor = champ->cursor;
  new->size = champ->size;
  new->id = champ->id;
  new->name = champ->name;
  new->reg[0][0] = champ->reg[0][0];
  new->reg[0][1] = champ->reg[0][1];
  new->reg[0][2] = champ->reg[0][2];
  new->reg[0][3] = champ->reg[0][3];
}

void	fill_new_fork(t_champ *new, t_champ *champ, int nb, unsigned char *board)
{
  int	i;

  i = -1;
  new->instru = champ->instru;
  while (++i < nb)
    moving_PC(new, board, 1);
  new->start = champ->start;
  new->cycle =  champ->cycle;
  new->cursor = champ->cursor;
  new->size = champ->size;
  new->id = champ->id;
  new->name = champ->name;
  new->reg[0][0] = champ->reg[0][0];
  new->reg[0][0] = champ->reg[0][1];
  new->reg[0][0] = champ->reg[0][2];
  new->reg[0][0] = champ->reg[0][3];
}

void	add_forking(t_vm *vm, t_champ *champ, int nb, unsigned char *board)
{
  int	i;
  t_champ	*tmp;
  t_decal_nb	decal_nb;
	
  i = 0;
  tmp = vm->begin;
  while (tmp)
    {
      if (my_strcmp(champ->name, tmp->name) == 0)
	break;
      tmp = tmp->next;
      i++;
    }
  decal_nb.decal = i +1;
  decal_nb.nb = nb;
  add_vm_somewhere(vm, champ, decal_nb, board);
}

void	add_list_end_vm(t_vm *vm, t_champ *champ)
{
  t_champ	*new;

  if (!vm)
    {
      my_putstr("add_list_end : list is NULL\nExit program\n");
      exit(EXIT_FAILURE);
    }
  new = xmalloc(sizeof(*new));
  fill_new(new, champ);
  new->next = NULL;
  new->prev = NULL;
  if (vm->begin == NULL)
    {
      vm->begin = new;
      vm->end = new;
      vm->nb = 1;
    }
  else
    {
      new->prev = vm->end;
      vm->end->next = new;
      vm->end = new;
      vm->nb = vm->nb + 1;
    }
}

t_vm	*new_vm(t_vm *vm)
{
  vm = xmalloc(sizeof(*vm));
  vm->begin = NULL;
  vm->end = NULL;
  vm->nb = 0;
  return (vm);
}
