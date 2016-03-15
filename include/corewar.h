/*
** corewar.h for  in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Mar  7 12:59:17 2016 Eric DESCHODT
<<<<<<< HEAD
<<<<<<< HEAD
** Last update Mon Mar 14 17:05:34 2016 Juliani Renaud
=======
** Last update Tue Mar  8 17:30:26 2016 Eric DESCHODT
>>>>>>> 4d69422aaf278a3bd23f86782f2c61c86cc97175
=======
** Last update Mon Mar 14 16:37:12 2016 Eric DESCHODT

>>>>>>> 0b4be3eac11405a6f4dd4dda1e1daf9f59f62ee6
*/

#ifndef COREWAR_H_
# define COREWAR_H_

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "op.h"
# include "myprintf.h"
# include "get_next_line.h"
# define MAGIC_NUMBER 85


<<<<<<< HEAD
typedef struct		s_instru
{
  op_t			ope;
  int			current_cycle;
  struct s_instru	*next;
}			t_instru;

typedef struct		s_headers
{
  int			magic;
  char			*name;
  char			*comment;
}			t_headers;

typedef struct		s_champlist
=======
typedef struct		s_champ
>>>>>>> 0b4be3eac11405a6f4dd4dda1e1daf9f59f62ee6
{
  char			reg[REG_NUMBER][T_REG];
  int			id;
  unsigned char		*instru;
  int			cycle;
  int			cursor;
  int			size;
  int			alive;
  op_t			ope;
  struct s_champ	*next;
  struct s_champ	*prev;
}			t_champ;

typedef struct		s_vm
{
  t_champ		*begin;
  t_champ		*end;
  int			nb;
}			t_vm;

void	my_puterror(char *str);
char	*my_memeset(char *str, char c, int len);

typedef union		u_byte
{
  char			byte[4];
  unsigned int		full;
}			t_byte;

void    *xmalloc(int size);
t_vm	*new_vm(t_vm *vm);
void	launch_vm(t_vm *vm, int nb_champ);
int     start_vm(t_vm *vm, unsigned char *board);

#endif /* !COREWAR_H */
