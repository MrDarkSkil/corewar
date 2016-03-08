/*
** add_list.c for add_list.c in /home/roig_a/Desktop/fct/link-list/simple
** 
** Made by Roig Antoine
** Login   <roig_a@epitech.net>
** 
** Started on  Sun Oct 11 20:25:22 2015 Roig Antoine
** Last update Thu Oct 15 11:32:00 2015 Roig Antoine
*/

#include "list.h"

void	add_list_begin(t_dlist *list, int value)
{
  t_list	*new;

  if (!list)
    {
      printf("add_list_begin : list is NULL\nExit program\n");
      exit(EXIT_FAILURE);
    }
  new = xmalloc(sizeof(*new));
  new->value = value;
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
      new->next = list->begin;
      list->begin->prev = new;
      list->begin = new;
      list->size = list->size + 1;
    }
}

void	add_list_end(t_dlist *list, int value)
{
  t_list	*new;

  if (!list)
    {
      printf("add_list_end : list is NULL\nExit program\n");
      exit(EXIT_FAILURE);
    }
  new = xmalloc(sizeof(*new));
  new->value = value;
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

void	add_list_somewhere2(t_dlist *list, t_list *new, int pos)
{
  t_list	*tmp;

  tmp = list->begin;
  while (pos != 0)
    {
      tmp = tmp->next;
      pos--;
    }
  tmp->prev->next = new;
  new->prev = tmp->prev;
  tmp->prev = new;
  new->next = tmp;
  list->size = list->size + 1;
}

void	add_list_somewhere(t_dlist *list, int value, int pos)
{
  t_list	*new;

  if (!list)
    {
      printf("add_list_somewhere : list is NULL\nExit program\n");
      exit(EXIT_FAILURE);
    }
  new = xmalloc(sizeof(*new));
  new->value = value;
  new->next = NULL;
  new->prev = NULL;
  if (pos <= 0)
    add_list_begin(list, value);
  else if (pos >= list->size)
    add_list_end(list, value);
  else 
    add_list_somewhere2(list, new, pos);
}
