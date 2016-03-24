/*
** list_champ2.c for list_champ2.c in /home/roig_a/COREWAR/coreware/src/corewar
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Mon Mar 21 17:39:07 2016 Antoine Roig
** Last update Thu Mar 24 01:10:18 2016 Antoine Roig
*/

#include <stdio.h>
#include "corewar.h"

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
      printf("cursor = %d\n", (tmp_v->cursor));
      printf("size = %d\n", (tmp_v->size));
      printf("alive = %d\n", (tmp_v->alive));
      write(1, "\n\n", 1);
      tmp_v = tmp_v->next;
    }
}
