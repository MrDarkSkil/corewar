/*
** list.c for list in /home/hubert_i/rendu/2015/INFO/gfx_scroller
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sat Mar 19 21:21:03 2016 Léo Hubert
** Last update Wed Mar 23 14:56:01 2016 Léo Hubert
*/

#include "compilator.h"

t_asm			*add_action(t_asm	*list,
				    char	*ins,
				    char	*param)
{
  t_asm			*newelem;

  if ((newelem = malloc(sizeof(t_asm))) == NULL)
    return (NULL);
  newelem->ins = ins;
  newelem->param = param;
  newelem->first = 0;
  newelem->next = NULL;
  newelem->prev = NULL;
  if (list == NULL)
    {
      newelem->first = 1;
      newelem->next = newelem;
      newelem->prev = newelem;
    }
  else
    {
      while (list->first != 1)
	list = list->next;
      newelem->prev = list->prev;
      newelem->next = list;
      list->prev->next = newelem;
      list->prev = newelem;
    }
  return (newelem);
}
