/*
** list.h for list.h in /home/roig_a/Desktop/fct/link-list/simple
** 
** Made by Roig Antoine
** Login   <roig_a@epitech.net>
** 
** Started on  Sun Oct 11 17:26:33 2015 Roig Antoine
** Last update Wed Oct 21 19:15:11 2015 Roig Antoine
*/

#ifndef _LIST_H_
# define _LIST_H_

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_list
{
  int			value;
  struct s_list		*next;
  struct s_list		*prev;
}	 t_list;

typedef struct		s_dlist
{
  t_list		*begin;
  t_list		*end;
  int			size;
}	t_dlist;

	/* utils_list */

void			*xmalloc(int);
t_dlist			*new_list(t_dlist*);
void			show_list(t_dlist *);
void			clear_list(t_dlist *list);
void			rev_list(t_dlist * list);
	/* add_list */

void			add_list_end(t_dlist *, int);
void			add_list_begin(t_dlist *, int);
void			add_list_somewhere(t_dlist *, int, int);
void			add_list_somewhere2(t_dlist *, t_list *, int);

	/* pop_list */

t_list			*pop_list_begin(t_dlist *);
t_list			*pop_list_end(t_dlist *);
t_list			*pop_list_somewhere(t_dlist *, int);
t_list			*pop_list_somewhere2(t_dlist *, int);

#endif
