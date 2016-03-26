/*
** util_list.c for utils_list.c in /home/roig_a/Desktop/fct/link-list/simple
** 
** Made by Roig Antoine
** Login   <roig_a@epitech.net>
** 
** Started on  Sun Oct 11 22:13:44 2015 Roig Antoine
** Last update Fri Mar 25 22:01:37 2016 Eric DESCHODT
*/

#include "corewar.h"

void		show_list(t_dlist *list)
{
  t_list	*tmp;

  tmp = list->begin;
  while (tmp != NULL)
    {
      my_putstr(tmp->arg);
      my_putchar('\n');
      tmp = tmp->next;
    }
}

t_dlist		*new_list(t_dlist *list)
{
  list = xmalloc(sizeof(*list));
  list->begin = NULL;
  list->end = NULL;
  list->size = 0;
  return (list);
}

void		clear_list(t_dlist *list)
{
  t_list	*tmp;

  tmp = list->begin;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      free(pop_list_begin(list));
    }
  free(tmp);
}

void		rev_list(t_dlist *list)
{
  t_list	*tmp;
  t_list	*pass;

  tmp = list->begin;
  while (tmp)
    {
      pass = tmp->next;
      tmp->next = tmp->prev;
      tmp->prev = pass;
      tmp = tmp->prev;
    }
  pass = list->begin;
  list->begin = list->end;
  list->end = pass;
}
