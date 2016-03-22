/*
** fork.c for  in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Mar 21 15:26:10 2016 Eric DESCHODT
** Last update Tue Mar 22 14:57:06 2016 Antoine Roig
*/

#include "corewar.h"

int		forking(t_vm *vm, t_champ *champ, unsigned char *board)
{
  t_byte	uni;

  my_printf("Fork\n");
  champ->ope.nbr_cycles = 800;
  uni.byte[0] = 0;
  uni.byte[1] = 0;
  uni.byte[2] = (*champ->instru++);
  uni.byte[3] = (*champ->instru);   
  revert_endian(&uni.full);
  uni.full %= IDX_MOD;
  add_forking(vm, champ, uni.full, board);
  return (0);
}
