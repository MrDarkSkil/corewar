/*
** xor.c for xor.c in /home/roig_a/COREWAR/coreware/src/corewar
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Mon Mar 21 12:55:15 2016 Antoine Roig
** Last update Fri Mar 25 22:02:06 2016 Eric DESCHODT
*/

#include "corewar.h"

void		xor2(void *champ,
		     t_byte *nb,
		     t_args *arg)
{
  t_byte	nb3;

  nb3.full = (nb[0].full ^ nb[1].full);
  ((t_champ *)champ)->reg[arg[2].val][0] = nb3.byte[0];
  ((t_champ *)champ)->reg[arg[2].val][1] = nb3.byte[1];
  ((t_champ *)champ)->reg[arg[2].val][2] = nb3.byte[2];
  ((t_champ *)champ)->reg[arg[2].val][3] = nb3.byte[3];
}

int		xor(t_args *arg,
		    void *champ,
		    unsigned char *board)
{
  t_byte	nb[2];
  int		i;

  (void)board;
  swap_carry(((t_champ *)champ));
  i = -1;
  if (arg[2].val <= 0 || arg[2].val > REG_NUMBER)
    return (0);
  while (++i < 2)
    {
      if (arg[i].type == 1)
	{
          if (arg[i].val <= 0 || arg[i].val > REG_NUMBER)
            return (0);
	  nb[i].byte[0] = ((t_champ *)champ)->reg[arg[i].val - 1][0];
	  nb[i].byte[1] = ((t_champ *)champ)->reg[arg[i].val - 1][1];
	  nb[i].byte[2] = ((t_champ *)champ)->reg[arg[i].val - 1][2];
	  nb[i].byte[3] = ((t_champ *)champ)->reg[arg[i].val - 1][3];
	}
      else
	nb[i].full = arg[i].val;
     xor2(champ, nb, arg);
    }
  return (0);
}
