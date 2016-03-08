/*
** util_list.c for utils_list.c in /home/roig_a/Desktop/fct/link-list/simple
** 
** Made by Roig Antoine
** Login   <roig_a@epitech.net>
** 
** Started on  Sun Oct 11 22:13:44 2015 Roig Antoine
** Last update Mon Mar  7 13:53:03 2016 Antoine Roig
*/

#include "list.h"

void	*xmalloc(int size)
{
  void	*element;

  element = malloc(size);
  if (!element)
    exit(EXIT_FAILURE);
  return (element);
}

void	show_list(t_dlist *list)
{
  t_list	*tmp;

  tmp = list->begin;
  while (tmp != NULL)
    {
      printf("%d\n", (tmp->value));
      tmp = tmp->next;
    }
}

t_dlist	*new_list(t_dlist *list)
{
  list = xmalloc(sizeof(*list));
  list->begin = NULL;
  list->end = NULL;
  list->nb = 0;
  return (list);
}

void	clear_list(t_dlist *list)
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

void	rev_list(t_dlist *list)
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
