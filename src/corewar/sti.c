/*
** start_vm.c for corewar in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Mar  7 13:35:33 2016 Eric DESCHODT
** Last update Mon Mar 21 16:47:56 2016 Eric DESCHODT
*/

#include "corewar.h"

int		sti(t_champ *champ, unsigned char *board)
{
  int		i;

  my_printf("Sti\n");
  i = -1;
  champ->ope.nbr_cycles = 25;
  while (++i < 6)
    moving_PC(champ, board, 1);
  return (0);
}
