/*
** list_champ.c for list_champ.c in /home/roig_a/coreware/coreware
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Fri Mar 18 18:34:50 2016 Antoine Roig
** Last update Tue Mar 22 14:17:41 2016 Antoine Roig
*/

#include "corewar.h"

void	fill_new(t_champ *new, t_champ *champ)
{
  new->instru = champ->instru;
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

void	fill_new_fork(t_champ *new, t_champ *champ, int nb)
{
  new->instru = champ->instru;
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

void	add_forking(t_vm *vm, t_champ *champ, int nb)
{
  int	i;
  t_champ	*tmp;

  i = 0;
  tmp = vm->begin;
  while (tmp)
    {
      if (my_strcmp(champ->name, tmp->name) == 0)
	break;
      tmp = tmp->next;
      i++;
    }
  add_vm_somewhere(vm, champ, i + 1, nb);
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

void    show_list_vm(t_vm *vm)
{
  t_champ        *tmp_v;

  tmp_v = vm->begin;
  my_printf("\nnb champ = %d\n", vm->nb);
  my_printf("dump = %d\n\n", vm->dump);
  while (tmp_v)
    {
      my_printf("instru = %p\n", tmp_v->instru);
      my_printf("start = %p\n", tmp_v->start);
      my_printf("id = %d\n", (tmp_v->id));
      my_printf("name = %s\n", (tmp_v->name));
      my_printf("cycle = %d\n", (tmp_v->cycle));
      my_printf("cursor =%d\n", (tmp_v->cursor));
      my_printf("size = %d\n", (tmp_v->size));
      my_printf("alive = %d\n", (tmp_v->alive));
      write(1, "\n\n", 1);
      tmp_v = tmp_v->next;
    }
}
