/*
** start_vm.c for corewar in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Mar  7 13:35:33 2016 Eric DESCHODT
** Last update Tue Mar 22 08:54:51 2016 Eric DESCHODT
*/

#include "corewar.h"

void		moving_PC(t_champ *champ, unsigned char *board, int move)
{
  champ->cursor += move;
  if (champ->cursor == MEM_SIZE)
    {
      champ->cursor = 0;
      champ->instru = &board[0];
    }
  else if (champ->cursor == -1)
    {
      champ->cursor = MEM_SIZE - 1;
      champ->instru = &board[MEM_SIZE - 1];
    }
  else
    champ->instru += move;
}
