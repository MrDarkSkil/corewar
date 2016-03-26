/*
** sub.c for sub.c in /home/roig_a/COREWAR/coreware
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Sun Mar 20 01:35:42 2016 Antoine Roig
** Last update Sat Mar 26 11:32:16 2016 Eric DESCHODT
*/

#include "corewar.h"

int		sub(t_args *arg, void *champ, unsigned char board[2][MEM_SIZE])
{
  t_byte	nb1;
  t_byte	nb2;
  t_byte        nb3;

  (void)board;
  swap_carry(((t_champ *)champ));
  if ((arg[0].val < 1 || arg[0].val >= REG_NUMBER)
      || (arg[1].val < 1 || arg[1].val >= REG_NUMBER)
      || (arg[2].val < 1 || arg[2].val >= REG_NUMBER))
    return (0);
  nb1.byte[0] = ((t_champ *)champ)->reg[arg[0].val - 1][0];
  nb1.byte[1] = ((t_champ *)champ)->reg[arg[0].val - 1][1];
  nb1.byte[2] = ((t_champ *)champ)->reg[arg[0].val - 1][2];
  nb1.byte[3] = ((t_champ *)champ)->reg[arg[0].val - 1][3];
  nb2.byte[0] = ((t_champ *)champ)->reg[arg[1].val - 1][0];
  nb2.byte[1] = ((t_champ *)champ)->reg[arg[1].val - 1][1];
  nb2.byte[2] = ((t_champ *)champ)->reg[arg[1].val - 1][2];
  nb2.byte[3] = ((t_champ *)champ)->reg[arg[1].val - 1][3];
  nb3.full = (nb1.full - nb2.full);
  ((t_champ *)champ)->reg[arg[2].val][0] = nb3.byte[0];
  ((t_champ *)champ)->reg[arg[2].val][1] = nb3.byte[1];
  ((t_champ *)champ)->reg[arg[2].val][2] = nb3.byte[2];
  ((t_champ *)champ)->reg[arg[2].val][3] = nb3.byte[3];
   return (0);
}
