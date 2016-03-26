/*
** start_vm.c for corewar in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Mar  7 13:35:33 2016 Eric DESCHODT
** Last update Fri Mar 25 21:57:40 2016 Eric DESCHODT
*/

#include "corewar.h"

void		decal_sti(int decal,
			  unsigned char *board,
			  t_champ *champ,
			  t_args *arg)
{
  int		i;

  (void)arg;
  i = -1;

  while (++i < decal - 2)
    moving_PC(champ, board, 1);
  i = -1;
  while (++i < 4)
    {
      *champ->instru = champ->reg[arg[0].val - 1][3 - i];
      moving_PC(champ, board, 1);
    }
  i = -1;
  while (++i < decal + 2)
    moving_PC(champ, board, -1);
}

int		sti(t_args *arg,
		    void *_champ,
		    unsigned char *board)
{
  t_champ	*champ;
  int		decal;
  int		back;
  int		i;

  champ = _champ;
  back = 1;
  i = 0;
  while (++i < 3)
    {
      if (arg[i].type == 1)
	{
	  decal = convert_reg(champ->reg[arg[i].val - 1]);
	  back += 1;
	}
      else
	{
	  decal += arg[i].val;
	  back +=2;
	}
    }
  decal_sti(decal - back - 2, board, champ, arg);
  return (0);
}
