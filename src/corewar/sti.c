/*
** start_vm.c for corewar in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Mar  7 13:35:33 2016 Eric DESCHODT
** Last update Fri Mar 18 21:51:40 2016 Eric DESCHODT
*/

#include "corewar.h"

int		sti(t_champ *champ, unsigned char *board)
{
  int		i;

  my_printf("Sti\n");
  i = -1;
  while (++i < 6)
    moving_PC(champ, board, 1);

  /* int		i; */
  /* unsigned char	*adr; */

  /* adr = ((t_champ *)champ)->start; */
  /* if (arg[1].type == 1) */
  /*   adr += convert_reg(((t_champ *)champ)->reg[arg[1].val]); */
  /* else */
  /*   adr += arg[1].val; */
  /* if (arg[2].type == 1) */
  /*   adr += convert_reg(((t_champ *)champ)->reg[arg[2].val]); */
  /* else */
  /*   adr += arg[2].val; */
  /* i = 0; */
  /* while (i < REG_SIZE) */
  /*   { */
  /*     *adr = ((t_champ *)champ)->reg[arg[0].val - 1][i]; */
  /*     adr++; */
  /*     i++; */
  /*   } */
  return (0);
}
