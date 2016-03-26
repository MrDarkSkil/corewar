/*
** fork.c for  in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Mar 21 15:26:10 2016 Eric DESCHODT
** Last update Sat Mar 26 08:44:53 2016 Eric DESCHODT
*/

#include "corewar.h"

int		forking(t_vm *vm,
			t_champ *champ,
			unsigned char *board,
			int var)
{
  t_byte	uni;

  if (vm->debug == 1)
    my_putstr("Fork\n");
  champ->ope.nbr_cycles = 800;
  uni.byte[0] = 0;
  uni.byte[1] = 0;
  uni.byte[2] = (*champ->instru++);
  uni.byte[3] = (*champ->instru);
  revert_endian(&uni.full);
  if (var == 1)
    {
      uni.full %= IDX_MOD;
      if (champ->carry == 0)
	champ->carry = 1;
      else
	champ->carry = 0;
    }
  add_forking(vm, champ, uni.full, board);
  return (0);
}
