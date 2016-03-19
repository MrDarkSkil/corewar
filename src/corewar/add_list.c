/*
** add_list.c for add_list.c in /home/roig_a/Desktop/fct/link-list/simple
** 
** Made by Roig Antoine
** Login   <roig_a@epitech.net>
** 
** Started on  Sun Oct 11 20:25:22 2015 Roig Antoine
** Last update Fri Mar 18 21:28:46 2016 Antoine Roig
*/

#include "corewar.h"

void	add_list_end(t_dlist *list, char *arg)
{
  t_list	*new;

  if (!list)
    {
      printf("add_list_end : list is NULL\nExit program\n");
      exit(EXIT_FAILURE);
    }
  new = xmalloc(sizeof(*new));
  new->arg = arg;
  new->next = NULL;
  new->prev = NULL;
  if (list->begin == NULL)
    {
      list->begin = new;
      list->end = new;
      list->size = 1;
    }
  else
    {
      new->prev = list->end;
      list->end->next = new;
      list->end = new;
      list->size = list->size + 1;
    }
}
