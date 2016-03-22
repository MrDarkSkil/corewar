/*
** start_vm.c for corewar in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Mar  7 13:35:33 2016 Eric DESCHODT
** Last update Tue Mar 22 13:55:33 2016 Eric DESCHODT
*/

#include "corewar.h"

int		sti(t_args *arg, void *_champ)
{
  t_champ	*champ;
  int		decal;
  int		back;
  int		i;
  unsigned char	*tmp;

  champ = _champ;
  back = 1;
  if (arg[1].type == 1)
    {
      decal = convert_reg(champ->reg[arg[1].val - 1]);
      back += 1;
    }
  else
    {
      decal = arg[1].val;
      back +=2;
    }
  if (arg[2].type == 1)
    {
      decal += convert_reg(champ->reg[arg[2].val - 1]);
      back += 1;
    }
  else
    {
      decal += arg[2].val;
      back +=2;
    }
  tmp = champ->instru - back + decal - 2;
  i = 3;
  while (i >= 0)
    {
      *tmp = champ->reg[0][i];
      tmp++;
      i--;
    }
  return (0);
}
