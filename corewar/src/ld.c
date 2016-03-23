/*
** start_vm.c for corewar in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
**
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
**
** Started on  Mon Mar  7 13:35:33 2016 Eric DESCHODT
** Last update Wed Mar 23 14:37:22 2016 Eric DESCHODT
*/

#include "corewar.h"

int		ld(t_args *arg, void *_champ, unsigned char *board)
{
  t_champ	*champ;

  champ = _champ;
  printf("%d\n", arg[0].type);
  printf("%d\n", arg[1].type);
  exit(0);
  (void)champ;
  (void)board;
  return (0);
}
