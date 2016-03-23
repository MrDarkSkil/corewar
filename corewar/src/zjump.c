/*
** start_vm.c for corewar in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Mar  7 13:35:33 2016 Eric DESCHODT
** Last update Wed Mar 23 09:15:07 2016 Eric DESCHODT
*/

#include "corewar.h"

void		zjump_move(t_champ *champ,
			   unsigned char *board,
			   t_byte tmp)
{
 int		i;

 i = -1;
 while (++i < 3)
   moving_PC(champ, board, -1);
 while (tmp.full != 0)
   {
      if (tmp.full < 0)
	{
	  moving_PC(champ, board, -1);
	  tmp.full++;
	}
      else
	{
	  moving_PC(champ, board, 1);
	  tmp.full--;
	}
   }
}

int		zjump(t_champ *champ,
		      unsigned char *board)
{
  t_byte	tmp;
  int		i;

  my_putstr("zjump\n");
  champ->ope.nbr_cycles = 20;
  i = -1;
  if (*champ->instru &  (1u << 0))
    tmp.full = -1;
  else
    tmp.full = 0;
  while (++i < IND_SIZE)
    {
      tmp.byte[4 - IND_SIZE + i] = (*champ->instru);
      moving_PC(champ, board, 1);
    }
  revert_endian(&tmp.full);
  tmp.full %= IDX_MOD;
  zjump_move(champ, board, tmp);
  return (0);
}