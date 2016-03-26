/*
** st.c for corewar in /home/julian_r/rendu/prog_elem/coreware/corewar/src
** 
** Made by Juliani Renaud
** Login   <julian_r@epitech.net>
** 
** Started on  Wed Mar 23 13:27:00 2016 Juliani Renaud
** Last update Sat Mar 26 11:28:49 2016 Eric DESCHODT
*/

#include "corewar.h"

void		st_2_pos(t_args *arg,
			 t_champ *champ,
			 unsigned char *board,
			 t_byte uni)
{
  int		i;

  if (arg[0].val < 1 || arg[0].val > REG_NUMBER)
    return;
  uni.byte[0] = champ->reg[arg[0].val - 1][0];
  uni.byte[1] = champ->reg[arg[0].val - 1][1];
  uni.byte[2] = champ->reg[arg[0].val - 1][2];
  uni.byte[3] = champ->reg[arg[0].val - 1][3];
  i = -1;
  while (++i < arg[1].val)
    moving_PC(champ, board, 1);
  i = 0;
  while (i < REG_SIZE)
    {
      champ->instru[i] = uni.byte[i];
      moving_PC(champ, board, 1);
      i++;
    }
  i = -1;
  while (++i < (arg[1].val + REG_SIZE))
    moving_PC(champ, board, -1);
}

void		st_2_neg(t_args *arg,
			 t_champ *champ,
			 unsigned char *board,
			 t_byte uni)
{
  int		i;

  i = 0;
  if (arg[0].val < 1 || arg[0].val > REG_NUMBER)
    return;
  uni.byte[0] = champ->reg[arg[0].val - 1][0];
  uni.byte[1] = champ->reg[arg[0].val - 1][1];
  uni.byte[2] = champ->reg[arg[0].val - 1][2];
  uni.byte[3] = champ->reg[arg[0].val - 1][3];
  while (i > arg[1].val)
    {
      moving_PC(champ, board, -1);
      i--;
    }
  i = 0;
  while (i < REG_SIZE)
    {
      champ->instru[i] = uni.byte[i];
      moving_PC(champ, board, 1);
      i++;
    }
  i = -1;
  while (++i < (arg[1].val + REG_SIZE))
    moving_PC(champ, board, 1);
}

void		st_reg(t_args *arg,
		       t_champ *champ,
		       t_byte uni)
{
  if (arg[1].val >= 1 && arg[1].val < REG_NUMBER)
    {
      uni.byte[0] = champ->reg[arg[0].val][0];
      uni.byte[1] = champ->reg[arg[0].val][1];
      uni.byte[2] = champ->reg[arg[0].val][2];
      uni.byte[3] = champ->reg[arg[0].val][3];
      champ->reg[arg[2].val][0] = uni.byte[0];
      champ->reg[arg[2].val][1] = uni.byte[1];
      champ->reg[arg[2].val][2] = uni.byte[2];
      champ->reg[arg[2].val][3] = uni.byte[3];
    }
}

int		st(t_args *arg,
		   void *_champ,
		   unsigned char board[2][MEM_SIZE])
{
  t_champ	*champ;
  t_byte	uni;

  champ = _champ;
  swap_carry(champ);
  if (arg[1].type == 1)
    st_reg(arg, champ, uni);
  else if (arg[1].type == 2 || arg[1].type == 4)
    {
      if (arg[1].val >= 0)
	st_2_pos(arg, champ, board[0], uni);
      else
	st_2_neg(arg, champ, board[0], uni);
    }
  return (0);
}
