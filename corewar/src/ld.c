/*
** start_vm.c for corewar in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
**
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
**
** Started on  Mon Mar  7 13:35:33 2016 Eric DESCHODT
** Last update Wed Mar 23 16:22:28 2016 Eric DESCHODT
*/

#include "corewar.h"

int		ld(t_args *arg,
		   void *_champ,
		   unsigned char *board)
{
  t_champ	*champ;
  int		i;

  i = -1;
  champ = _champ;
  swap_carry(champ);
  if (arg[1].val <= 0 || arg[1].val > 15)
    return (0);
  if (arg[0].val > 0)
    {
      while (++i < arg[0].val % IDX_MOD)
	moving_PC(champ, board, 1);

      i = -1;
      while (++i < REG_SIZE)
	{
	  champ->reg[arg[1].val - 1][i] = *champ->instru;
	  moving_PC(champ, board, 1);
	}
      printf("chips\n");
      i = -1;
      while (++i < REG_SIZE + arg[0].val % IDX_MOD)
	moving_PC(champ, board, -1);
    }
  else
    {
      arg[0].val = - arg[0].val;
      while (++i < arg[0].val % IDX_MOD)
	moving_PC(champ, board, -1);
      i = -1;
      while (++i < REG_SIZE)
	{
	  champ->reg[arg[1].val - 1][i] = *champ->instru;
	  moving_PC(champ, board, 1);
	}
      i = -1;
      while (++i < arg[0].val % IDX_MOD - REG_SIZE)
	moving_PC(champ, board, 1);
    }
  return (0);
}
