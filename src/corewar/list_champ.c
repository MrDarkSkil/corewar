/*
** list_champ.c for list_champ.c in /home/roig_a/coreware/coreware
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Fri Mar 18 18:34:50 2016 Antoine Roig
** Last update Fri Mar 18 22:20:17 2016 Antoine Roig
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

void	add_list_end_vm(t_vm *vm, t_champ *champ)
{
  t_champ	*new;

  if (!vm)
    {
      printf("add_list_end : list is NULL\nExit program\n");
      exit(EXIT_FAILURE);
    }
  new = malloc(sizeof(*new));
  fill_new(new, champ);
  new->next = NULL;
  new->prev = NULL;
  if (vm->begin == NULL)
    {
      printf("ICI\n");
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
  printf("\nnb champ = %d\n", vm->nb);
  printf("dump = %d\n\n", vm->dump);
  while (tmp_v)
    {
      printf("instru = %p\n", tmp_v->instru);
      printf("start = %p\n", tmp_v->start);
      printf("id = %d\n", (tmp_v->id));
      printf("name = %s\n", (tmp_v->name));
      printf("cycle = %d\n", (tmp_v->cycle));
      printf("cursor =%d\n", (tmp_v->cursor));
      printf("size = %d\n", (tmp_v->size));
      printf("alive = %d\n", (tmp_v->alive));
      write(1, "\n\n", 1);
      tmp_v = tmp_v->next;
    }
}
