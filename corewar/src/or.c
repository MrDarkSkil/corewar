/*
** or.c for or.c in /home/roig_a/COREWAR/coreware/src/corewar
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Mon Mar 21 12:48:24 2016 Antoine Roig
** Last update Wed Mar 23 14:18:37 2016 Antoine Roig
*/

#include "corewar.h"

void or2(void *champ, t_byte *nb, t_args *arg)
{
  t_byte	nb3;

  nb3.full = (nb[0].full | nb[1].full);
  ((t_champ *)champ)->reg[arg[2].val][0] = nb3.byte[0];
  ((t_champ *)champ)->reg[arg[2].val][1] = nb3.byte[1];
  ((t_champ *)champ)->reg[arg[2].val][2] = nb3.byte[2];
  ((t_champ *)champ)->reg[arg[2].val][3] = nb3.byte[3];
}

int	or(t_args *arg, void *champ, unsigned char *board)
{
  t_byte	nb[2];
  int		i;

  (void)board;
  i = -1;
  while (++i < 2)
    {
      if (arg[i].type == 1)
	{
	  nb[i].byte[0] = ((t_champ *)champ)->reg[arg[i].val - 1][0];
	  nb[i].byte[1] = ((t_champ *)champ)->reg[arg[i].val - 1][1];
	  nb[i].byte[2] = ((t_champ *)champ)->reg[arg[i].val - 1][2];
	  nb[i].byte[3] = ((t_champ *)champ)->reg[arg[i].val - 1][3];
	}
      else
	nb[i].full = arg[i].val;
      or2(champ, nb, arg);
    }
  swap_carry(((t_champ *)champ));
  return (0);
}

