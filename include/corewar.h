/*
** corewar.h for  in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Mar  7 12:59:17 2016 Eric DESCHODT
** Last update Mon Mar  7 13:49:06 2016 Eric DESCHODT
*/

#ifndef COREWAR_H_
# define COREWAR_H_

# include "op.h"

typedef struct		s_instru
{
  op_t			ope;
  int			current_cycle;
  struct s_instru	*next;
}			t_instru;

typedef struct		s_champlist
{
  t_instru		*begin;
  t_instru		*end;
  int			id;
  struct s_champlist	*next;
}			t_champlist;

typedef struct		s_vm
{
  t_champlist		*begin;
  t_champlist		*end;
  int			nb;
}			t_vm;

#endif /* !COREWAR_H */
