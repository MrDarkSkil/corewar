/*
** corewar.h for  in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Mar  7 12:59:17 2016 Eric DESCHODT
** Last update Fri Mar 11 11:24:40 2016 Juliani Renaud
*/

#ifndef COREWAR_H_
# define COREWAR_H_

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "op.h"
# include "myprintf.h"
# include "get_next_line.h"


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
  t_instru		*current;
  int			id;
  struct s_champlist	*next;
  struct s_champlist	*prev;
}			t_champlist;

typedef struct		s_vm
{
  t_champlist		*begin;
  t_champlist		*end;
  int			nb;
}			t_vm;

void	my_puterror(char *str);
char	*my_memeset(char *str, char c, int len);
void    *xmalloc(int size);
t_vm	*new_vm(t_vm *vm);
void	launch_vm(t_vm *vm, int nb_champ);
int     start_vm(t_vm *vm);

#endif /* !COREWAR_H */
