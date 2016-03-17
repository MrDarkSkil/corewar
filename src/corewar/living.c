/*
** start_vm.c for corewar in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Mar  7 13:35:33 2016 Eric DESCHODT
** Last update Thu Mar 17 11:32:32 2016 Eric DESCHODT
*/

#include "corewar.h"

void		find_living_champion(int result,
				     t_champ *champ)
{
  t_champ	*start;

  start = champ;
  if (start->reg[0][0] == result)
    {
      my_printf("Le champion (%d) est en vie\n", result);
      return;
    }
  start = start->next;
  while (start != champ)
    {
      if (start->reg[0][0] == result)
	{
	  my_printf("Le champion (%d) est en vie\n", result);
	  return;
	}
      start = start->next;
    }
}

void		living(t_champ *champ)
{
  int		i;
  int		pow;
  int		result;

  champ->instru++;
  champ->cursor++;
  i = 0;
  result = 0;
  pow = 16 * 16 * 16;
  while (i < 4)
    {
      result += pow * (*champ->instru);
      champ->instru++;
      champ->cursor++;
      i++;
      pow /= 16;
    }
  find_living_champion(result, champ);
}
