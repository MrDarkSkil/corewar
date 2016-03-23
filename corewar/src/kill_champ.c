/*
** kill_champ.c for kill_champ in /home/roig_a/COREWAR/coreware
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Wed Mar 23 10:10:39 2016 Antoine Roig
** Last update Wed Mar 23 22:26:23 2016 Eric DESCHODT
*/

#include "corewar.h"

t_champ		*pop_vm_begin(t_vm *vm)
{
  t_champ       *tmp;

  if (!vm)
    {
      my_putstr("pop_list_begin : list NULL\n");
      exit(EXIT_FAILURE);
    }
  if (vm->begin == NULL || vm->end == NULL)
    return (NULL);
  tmp = vm->begin;
  if (vm->nb == 1)
    {
      vm->begin = NULL;
      vm->end = NULL;
      vm->nb = vm->nb - 1;
      return (tmp);
    }
  vm->begin = tmp->next;
  tmp->next->prev = NULL;
  tmp->next = NULL;
  vm->nb = vm->nb - 1;
  return (tmp);
}

t_champ		*pop_vm_end(t_vm *vm)
{
  t_champ       *tmp;

  if (!vm)
    {
      my_putstr("pop_list_begin : list NULL\n");
      exit(EXIT_FAILURE);
    }
  if (vm->begin == NULL || vm->end == NULL)
    return (NULL);
  tmp = vm->end;
  if (vm->nb == 1)
    {
      vm->begin = NULL;
      vm->end = NULL;
      vm->nb = vm->nb-1;
      return (tmp);
    }
  vm->end = tmp->prev;
  tmp->prev->next = NULL;
  tmp->prev = NULL;
  vm->nb = vm->nb - 1;
  return (tmp);
}

t_champ		*pop_vm_somewhere2(t_vm *vm, int pos)
{
  t_champ       *tmp;

  tmp = vm->begin;
  while (pos != 0)
    {
      tmp = tmp->next;
      pos--;
    }
  tmp->prev->next = tmp->next;
  tmp->next->prev = tmp->prev;
  tmp->next = NULL;
  tmp->prev = NULL;
  vm->nb = vm->nb - 1;
  return (tmp);
}

t_champ	       *pop_vm_somewhere(t_vm *vm, int pos)
{
  t_champ      *tmp;

  if (!vm)
    {
      my_putstr("pop_list_begin : list NULL\n");
      exit(EXIT_FAILURE);
    }
  if (vm->begin == NULL || vm->end == NULL)
    return (NULL);
  if (pos <= 0)
    return (pop_vm_begin(vm));
  else if (pos >= vm->nb)
    return (pop_vm_end(vm));
  else
    return (pop_vm_somewhere2(vm, pos));
  return (tmp);
}

void		kill_champ(t_vm *vm)
{
  t_champ	*tmp;
  int		i;

  i = 0;
  tmp = vm->begin;
  while (tmp)
    {
      if (tmp->alive == 0)
	{
	  tmp = pop_vm_somewhere(vm, i);
	  free(tmp);
	  return;
	}
	i++;
      tmp = tmp->next;
    }
  return;
}
