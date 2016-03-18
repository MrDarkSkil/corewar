/*
** start_vm.c for corewar in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Mar  7 13:35:33 2016 Eric DESCHODT
** Last update Fri Mar 18 12:28:07 2016 Eric DESCHODT
*/

#include "corewar.h"

void		decal(char in[2],
		      t_champ *champ,
		      t_args *arg)
{
  int		mv;
  int		i;
  t_byte	tmp;

  i = 0;
  if (in[0] == 0 && in[1] == 1)
    mv = 1;
  else if (in[0] == 1 && in[1] == 0)
    mv = T_DIR;
  else if (in[0] == 1 && in[1] == 1)
    mv = T_IND;
  arg->type = mv;
  arg->val = 0;
  tmp.full = 0;
  i = -1;
  while (++i < mv)
    {
      tmp.byte[4 - mv + i] = (*champ->instru);
      champ->instru += 1;
      champ->cursor += 1;
    }
  i = -1;
  revert_endian(&tmp.full);
  arg->val = tmp.full;
}

int		convert_reg(char *nbr)
{
  int		i;
  t_byte	result;

  i = -1;
  while (++i < REG_SIZE)
    result.byte[i] = nbr[i];
  return (result.full);
}

int		sti(t_args *arg, void *champ)
{
  int		i;
  unsigned char	*adr;

  adr = ((t_champ *)champ)->start;
  if (arg[1].type == 1)
    adr += convert_reg(((t_champ *)champ)->reg[arg[1].val]);
  else
    adr += arg[1].val;
  if (arg[2].type == 1)
    adr += convert_reg(((t_champ *)champ)->reg[arg[2].val]);
  else
    adr += arg[2].val;
  i = 0;
  while (i < REG_SIZE)
    {
      *adr = ((t_champ *)champ)->reg[arg[0].val - 1][i];
      adr++;
      i++;
    }
  return (0);
}

typedef struct	s_test
{
  unsigned char	byte[2];
  short int	full;
}		t_test;

int		zjump2(t_champ *champ)
{
  t_byte	tmp;
  int		i;

  i = -1;
  if (*champ->instru &  (1u << 0))
    tmp.full = -1;
  else
    tmp.full = 0;
  while (++i < IND_SIZE)
    {
      tmp.byte[4 - IND_SIZE + i] = (*champ->instru);
      champ->instru += 1;
      champ->cursor += 1;
    }

  revert_endian(&tmp.full);
  tmp.full %= IDX_MOD;
  /* my_printf("%d\n", tmp.full); */
  champ->instru -= 4;
  champ->instru += tmp.full;
  /* my_printf("%d\n", *champ->instru); */
  return (0);
}

void		get_jump(t_champ *champ,
			 unsigned char*board,
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
  if (reference->func != NULL)
    reference->func(arg, champ);
}

void		load_instru(t_champ *champ,
			    unsigned char*board)
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
  else if (i == 8)
    zjump2(champ);
  else
    {
      champ->ope.nbr_cycles = op_tab[i].nbr_cycles;
      champ->ope.nbr_args = op_tab[i].nbr_args;
      my_printf("Champion : %d commande : %s qui prend %d cycles\n",
		champ->reg[0][3],
		op_tab[i].mnemonique, op_tab[i].nbr_cycles);
      get_jump(champ, board, &op_tab[i]);
    }
}
