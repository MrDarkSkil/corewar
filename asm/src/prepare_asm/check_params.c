/*
** check_params.c for check_params in /home/hubert_i/rendu/2015/coreware/asm/src/prepare_asm
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Fri Mar 25 19:15:23 2016 Léo Hubert
** Last update Fri Mar 25 19:28:34 2016 Léo Hubert
*/

#include		"compilator.h"

int			init_ptIns(int (*ptIns[17])(char *param))
{
  ptIns[0] = check_live;
  ptIns[1] = check_ld;
  ptIns[2] = check_st;
  ptIns[3] = check_add;
  ptIns[4] = check_sub;
  ptIns[5] = check_and;
  ptIns[6] = check_or;
  ptIns[7] = check_xor;
  ptIns[8] = check_zjmp;
  ptIns[9] = check_ldi;
  ptIns[10] = check_sti;
  ptIns[11] = check_fork;
  ptIns[12] = check_lld;
  ptIns[13] = check_lldi;
  ptIns[14] = check_lfork;
  ptIns[15] = check_aff;
  ptIns[16] = NULL;
  return (0);
}

int			check_param(char *ins, char *param)
{
  int	(*ptIns[17])(char *param);
  int	i;

  i = -1;
  init_ptIns(ptIns);
  while (op_tab[++i].mnemonique)
    {
      if (my_strcmp(op_tab[i].mnemonique, ins) == 0)
	return (ptIns[i](param));
    }
  return (-1);
}
