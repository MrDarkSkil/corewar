/*
** xor.c for xor.c in /home/roig_a/COREWAR/coreware/src/corewar
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Mon Mar 21 12:55:15 2016 Antoine Roig
** Last update Sat Mar 26 11:38:50 2016 Eric DESCHODT
*/

#include "corewar.h"

int		aff(t_args *arg,
		    void *_champ,
		    unsigned char board[2][MEM_SIZE])
{
  t_byte	nb;
  int		i;
  t_champ	*champ;

  (void)board;
  champ = _champ;
  i = -1;
  if (arg[0].val <= 0 || arg[0].val > REG_NUMBER)
    return (0);
  while (++i < 4)
    nb.byte[i] = champ->reg[arg[0].val - 1][i];
  my_putchar(nb.full % 256);
  return (0);
}
