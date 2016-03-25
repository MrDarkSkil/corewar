/*
** pop_list.c for pop_list.c in /home/roig_a/Desktop/fct/link-list/simple
** 
** Made by Roig Antoine
** Login   <roig_a@epitech.net>
** 
** Started on  Sun Oct 11 22:15:40 2015 Roig Antoine
** Last update Thu Mar 24 18:51:48 2016 Antoine Roig
*/

#include "corewar.h"

t_list	*pop_list_begin(t_dlist *list)
{
  t_list	*tmp;

  if (!list)
    {
      my_putstr("pop_list_begin : list NULL\n");
      exit(EXIT_FAILURE);
    }
  if (list->begin == NULL || list->end == NULL)
    return (NULL);
  tmp = list->begin;
  if (list->size == 1)
    {
      list->begin = NULL;
      list->end = NULL;
      list->size = list-> size - 1;
      return (tmp);
    }
  list->begin = tmp->next;
  tmp->next->prev = NULL;
  tmp->next = NULL;
  list->size = list-> size - 1;
  return (tmp);
}

t_list  *pop_list_somewhere2(t_dlist *list, int pos)
{
  t_list        *tmp;

  tmp = list->begin;
  while (pos != 0)
    {
      tmp = tmp->next;
      pos--;
    }
  tmp->prev->next = tmp->next;
  tmp->next->prev = tmp->prev;
  tmp->next = NULL;
  tmp->prev = NULL;
  list->size = list->size - 1;
  return (tmp);
}

t_list  *pop_list_somewhere(t_dlist *list, int pos)
{
  if (!list)
    {
      my_putstr("pop_list_begin : list NULL\n");
      exit(EXIT_FAILURE);
    }
  if (list->begin == NULL || list->end == NULL)
    return (NULL);
  if (pos <= 0)
    return (pop_list_begin(list));
  else if (pos >= list->size)
    return (pop_list_end(list));
  else
    return (pop_list_somewhere2(list, pos));
}

t_list  *pop_list_end(t_dlist *list)
{
  t_list        *tmp;

  if (!list)
    {
      my_putstr("pop_list_begin : list NULL\n");
      exit(EXIT_FAILURE);
    }
  if (list->begin == NULL || list->end == NULL)
    return (NULL);
  tmp = list->end;
  if (list->size == 1)
    {
      list->begin = NULL;
      list->end = NULL;
      list->size = list-> size - 1;
      return (tmp);
    }
  list->end = tmp->prev;
  tmp->prev->next = NULL;
  tmp->prev = NULL;
  list->size = list-> size - 1;
  return (tmp);
}
