/*
** main.c for main.c in /home/roig_a/Desktop/fct/link-list/simple
** 
** Made by Roig Antoine
** Login   <roig_a@epitech.net>
** 
** Started on  Sun Oct 11 20:18:15 2015 Roig Antoine
** Last update Tue Mar  8 15:29:14 2016 Juliani Renaud
*/

#include "list.h"

int	main()
{
  t_dlist	*list;

  list = NULL;
  list = new_list(list);
  add_list_begin(list, 10);
  add_list_begin(list, 20);
  add_list_begin(list, 30);
  add_list_begin(list, 40);
  add_list_begin(list, 50);
  add_list_somewhere(list, 42, 2);
  show_list(list);
  while (list->begin)
    pop_list_begin(list);
  write(1, "a", 1);
  show_list(list);
}
