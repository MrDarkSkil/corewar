/*
** start_vm.c for corewar in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Mar  7 13:35:33 2016 Eric DESCHODT
** Last update Wed Mar 23 21:29:15 2016 Eric DESCHODT
*/

#include "corewar.h"

void		aff_alive(int result, t_champ *champ)
{
  champ->alive = 1;
  revert_endian(&result);
  my_putstr("Le champion ");
  my_put_nbr(result);
  my_putstr(" (");
  my_putstr(champ->name);
  my_putstr(") est en vie\n");
}
void		find_living_champion(int result,
				     t_champ *champ)
{
  t_champ	*start;
  t_byte	tmp;
  int		i;

  i = -1;
  while (++i < REG_SIZE)
    tmp.byte[i] = champ->reg[0][i];
  revert_endian(&tmp.full);
  start = champ;

  while (start->prev != NULL)
    start = start->prev;
  while (start != NULL)
    {
      if (tmp.full == result)
	{
	  aff_alive(result, champ);
	  return;
	}
      start = start->next;
    }
}

void		living(t_champ *champ, unsigned char *board)
{
  int		i;
  int		result;
  t_byte	tmp;

  i = 0;
  tmp.full = 0;
  result = 0;
  champ->ope.nbr_cycles = 10;
  while (i < 4)
    {
      tmp.byte[i] = (*champ->instru);
      moving_PC(champ, board, 1);
      i++;
    }
  result = tmp.full;
  find_living_champion(result, champ);
}
