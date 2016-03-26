/*
** list_champ2.c for list_champ2.c in /home/roig_a/COREWAR/coreware/src/corewar
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Mon Mar 21 17:39:07 2016 Antoine Roig
** Last update Fri Mar 25 21:47:18 2016 Eric DESCHODT
*/

#include "corewar.h"

void    add_list_begin_vm(t_vm *vm, t_champ *champ)
{
  t_champ        *new;

  if (!vm)
    {
      my_putstr("add_vm_begin : vm is NULL\nExit program\n");
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
      new->next = vm->begin;
      vm->begin->prev = new;
      vm->begin = new;
      vm->nb = vm->nb + 1;
    }
}

void    add_vm_somewhere2(t_vm *vm,
			  t_champ *new,
			  int pos)
{
  t_champ        *tmp;

  tmp = vm->begin;
  while (pos != 0)
    {
      tmp = tmp->next;
      pos--;
    }
  tmp->prev->next = new;
  new->prev = tmp->prev;
  tmp->prev = new;
  new->next = tmp;
  vm->nb = vm->nb + 1;
}

void    add_vm_somewhere(t_vm *vm,
			 t_champ *champ,
			 t_decal_nb decal_nb,
			 unsigned char *board)
{
  t_champ     *new;

  if (!vm)
    {
      my_putstr("add_vm_somewhere : vm is NULL\nExit program\n");
      exit(EXIT_FAILURE);
    }
  new = xmalloc(sizeof(*new));
  fill_new_fork(new, champ, decal_nb.nb, board);
  new->next = NULL;
  new->prev = NULL;
  if (decal_nb.decal <= 0)
    add_list_begin_vm(vm, new);
  else if (decal_nb.decal >= vm->nb)
    add_list_end_vm(vm, new);
  else
    add_vm_somewhere2(vm, new, decal_nb.decal);
}
