/*
** xor.c for xor.c in /home/roig_a/COREWAR/coreware/src/corewar
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Mon Mar 21 12:55:15 2016 Antoine Roig
** Last update Tue Mar 22 17:22:46 2016 Antoine Roig
*/

#include "corewar.h"

int	xor(t_args *arg, void *champ)
{
  t_byte	nb1;
  t_byte	nb2;
  t_byte        nb3;

  if (arg[2].type != 1)
    return (0);
  else
    {
      if (arg[0].type == 1)
	{
	  nb1.byte[0] = ((t_champ *)champ)->reg[arg[0].val - 1][0];
	  nb1.byte[1] = ((t_champ *)champ)->reg[arg[0].val - 1][1];
	  nb1.byte[2] = ((t_champ *)champ)->reg[arg[0].val - 1][2];
	  nb1.byte[3] = ((t_champ *)champ)->reg[arg[0].val - 1][3];
	}
      else
	nb1.full = arg[0].val;
      if (arg[1].type == 1)
	{
	  nb2.byte[0] = ((t_champ *)champ)->reg[arg[1].val - 1][0];
	  nb2.byte[1] = ((t_champ *)champ)->reg[arg[1].val - 1][1];
	  nb2.byte[2] = ((t_champ *)champ)->reg[arg[1].val - 1][2];
	  nb2.byte[3] = ((t_champ *)champ)->reg[arg[1].val - 1][3];
	}
      else
	nb2.full = arg[1].val;
      nb3.full = (nb1.full ^ nb2.full);
      ((t_champ *)champ)->reg[arg[2].val][0] = nb3.byte[0];
      ((t_champ *)champ)->reg[arg[2].val][1] = nb3.byte[1];
      ((t_champ *)champ)->reg[arg[2].val][2] = nb3.byte[2];
      ((t_champ *)champ)->reg[arg[2].val][3] = nb3.byte[3];
    }
  swap_carry(((t_champ *)champ));
  return (0);
}
