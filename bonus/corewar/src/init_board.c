/*
** init_board.c for init_board.c in /home/roig_a/COREWAR/coreware/corewar
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Fri Mar 25 14:19:58 2016 Antoine Roig
** Last update Sat Mar 26 09:42:49 2016 Eric DESCHODT
*/

#include "corewar.h"

void		init_board(unsigned char board[2][MEM_SIZE])
{
  int		i;

  i = 0;
  while (i < MEM_SIZE)
    {
      board[0][i] = 0;
      board[1][i] = 0;
      i++;
    }
}

void		printboard(unsigned char *board)
{
  int		i;

  i = 0;
  while (i < MEM_SIZE)
    {
      if (board[i] < 16)
	my_putchar(' ');
      my_put_nbr_base(board[i], "0123456789abcdef");
      i++;
    }
  my_putchar('\n');
}
