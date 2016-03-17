/*
** start_vm.c for corewar in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Mar  7 13:35:33 2016 Eric DESCHODT
** Last update Thu Mar 17 11:36:53 2016 Eric DESCHODT
*/

#include "corewar.h"

void		decal(char in[2],
		      t_champ *champ,
		      t_args *arg)
{
  int		mv;
  int		i;
  int		pow;

  pow = 1;
  i = 0;
  if (in[0] == 0 && in[1] == 1)
    mv = T_REG;
  else if (in[0] == 1 && in[1] == 0)
    mv = T_DIR;
  else if (in[0] == 1 && in[1] == 1)
    mv = T_IND;
  arg->type = mv;
  i = 0;
  while (++i < mv)
    pow *= 16;
  arg->val = 0;
  i = -1;
  while (++i < mv)
    {
      arg->val += pow * (*champ->instru);
      pow /= 16;
      champ->instru += 1;
      champ->cursor += 1;
    }
}

void		get_jump(t_champ *champ,
			 unsigned char *board,
			 op_t *reference)
{
  int		i;
  int		j;
  char		c;
  char		in[2];
  t_args	arg[4];

  (void)board;
  c = *champ->instru;
  champ->instru++;
  champ->cursor++;
  i = 8;
  j = 0;
  while (--i >= 0 && j < reference->nbr_args)
    {
      if (c & (1u << i))
	in[(i % 2 == 1) ? 0 : 1] = 1;
      else
	in[(i % 2 == 1) ? 0 : 1] = 0;
      if (i % 2 == 0)
	decal(in, champ, &arg[j++]);
    }
}
void		load_instru(t_champ *champ,
			    unsigned char *board)
{
  int		i;

  i = 0;
  while (op_tab[i].code != *champ->instru && op_tab[i].code != 0)
    i++;
  champ->instru += 1;
  champ->cursor += 1;
  if (i == 16)
    {
      champ->ope.nbr_cycles = 1;
      champ->ope.nbr_args = 1;
    }
  else if (i == 0)
    living(champ);
  else
    {
      champ->ope.nbr_cycles = op_tab[i].nbr_cycles;
      champ->ope.nbr_args = op_tab[i].nbr_args;
      my_printf("Champion : %d commande : %s qui prend %d cycles\n",
		champ->reg[0][0],
		op_tab[i].mnemonique, op_tab[i].nbr_cycles);
      get_jump(champ, board, &op_tab[i]);
    }
}
