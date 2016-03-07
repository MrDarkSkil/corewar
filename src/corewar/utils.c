/*
** utils.c for utils.c in /home/roig_a/Corewar/coreware
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Mon Mar  7 15:53:27 2016 Antoine Roig
** Last update Mon Mar  7 15:58:01 2016 Antoine Roig
*/

#include "corewar.h"

void    *xmalloc(int size)
{
  void  *element;

  element = malloc(size);
  if (!element)
    exit(EXIT_FAILURE);
  return (element);
}

/* void    show_list(t_vm *vm) */
/* { */
/*   t_champlist        *tmp; */

/*   tmp = vm->begin; */
/*   while (tmp != NULL) */
/*     { */
/*       printf("id = %d\ncomment = %s\nnb cycle = %d", (tmp->id), tmp->begin->ope.comment, tmp->begin->ope.nbr_cycles); */
/*       tmp = tmp->next; */
/*     } */
/* } */
