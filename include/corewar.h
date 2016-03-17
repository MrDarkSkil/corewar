/*
** corewar.h for  in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Mar  7 12:59:17 2016 Eric DESCHODT
** Last update Thu Mar 17 18:13:30 2016 Eric DESCHODT
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

typedef struct		s_champ
{
  char			reg[REG_NUMBER][REG_SIZE];
  int			id;
  unsigned char		*instru;
  unsigned char		*start;
  int			cycle;
  int			cursor;
  int			size;
  int			alive;
  op_t			ope;
  char			carry;
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
void    *xmalloc(int size);

t_vm	*new_vm(t_vm *vm);
void	launch_vm(t_vm *vm, int nb_champ);
int     start_vm(t_vm *vm, unsigned char *board);
void    find_living_champion(int result, t_champ *champ);
void    living(t_champ *champ);
void	load_instru(t_champ *champ, unsigned char *board);

void    revert_endian(int *nb);
void    print_info(header_t *head);
int     convert_reg(char *nbr);
void    printboard(unsigned char *board);

int     sti(t_args *arg, void *champ);
int     zjump(t_args *arg, void *champ);

#endif /* !COREWAR_H */
