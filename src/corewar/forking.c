/*
** fork.c for  in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Mar 21 15:26:10 2016 Eric DESCHODT
** Last update Tue Mar 22 13:40:03 2016 Antoine Roig
*/

#include "corewar.h"

int		forking(t_champ *champ, unsigned char *board)
{
  t_byte	uni;

  my_printf("Fork\n");
  champ->ope.nbr_cycles = 800;
  uni.byte[3] = (*champ->instru++);
  uni.byte[4] = (*champ->instru);   
  revert_endian(&uni.full);
  /* uni.full %= IDX_M0D; */
  /* add_forking(vm, champ, uni.full); */
  return (0);
}
