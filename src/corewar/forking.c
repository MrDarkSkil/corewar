/*
** fork.c for  in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Mar 21 15:26:10 2016 Eric DESCHODT
** Last update Mon Mar 21 16:47:11 2016 Eric DESCHODT
*/

#include "corewar.h"

int		forking(t_champ *champ, unsigned char *board)
{
  int           i;

  my_printf("Fork\n");
  champ->ope.nbr_cycles = 800;
  i = -1;
  while (++i < 2)
    moving_PC(champ, board, 1);
  return (0);
}
