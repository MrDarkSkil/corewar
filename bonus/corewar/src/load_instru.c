/*
** start_vm.c for corewar in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Mar  7 13:35:33 2016 Eric DESCHODT
** Last update Sat Mar 26 11:37:46 2016 Eric DESCHODT
*/

#include "corewar.h"

void		get_arg(t_args *arg,
			t_champ *champ,
			unsigned char *board,
			int mv)
{
  int		i;
  t_byte	tmp;

  arg->val = 0;
  tmp.full = 0;
  i = -1;
  while (++i < mv)
    {
      tmp.byte[4 - mv + i] = (*champ->instru);
      moving_PC(champ, board, 1);
    }
  revert_endian(&tmp.full);
  arg->val = tmp.full;
}

void		decal(char in[2],
		      t_champ *champ,
		      t_args *arg,
		      unsigned char *board)
{
  int		mv;

  if (in[0] == 0 && in[1] == 1)
    mv = 1;
  else if (in[0] == 1 && in[1] == 0)
    mv = T_DIR;
  else if (in[0] == 1 && in[1] == 1)
    mv = T_IND;
  else
    mv = T_DIR;
  arg->type = mv;
  if ((champ->ope.code == 10 || champ->ope.code == 11
       || champ->ope.code == 14) && mv == 4)
    mv = IND_SIZE;
  else if ((champ->ope.code != 10 && champ->ope.code != 11
	    && champ->ope.code != 14) && mv == T_DIR)
    mv = DIR_SIZE;
  else if ((champ->ope.code != 10 && champ->ope.code != 11
	    && champ->ope.code != 14) && mv == T_IND)
    mv = IND_SIZE;
  get_arg(arg, champ, board, mv);
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

void		get_jump(t_champ *champ,
			 unsigned char board[2][MEM_SIZE],
			 op_t *reference)
{
  int		i;
  int		j;
  char		c;
  char		in[2];
  t_args	arg[4];

  c = *champ->instru;
  i = 8;
  j = 0;
  moving_PC(champ, board[0], 1);
  while (--i >= 0 && j < reference->nbr_args)
    {
      if (c & (1u << i))
	in[(i % 2 == 1) ? 0 : 1] = 1;
      else
	in[(i % 2 == 1) ? 0 : 1] = 0;
      if (i % 2 == 0)
      	decal(in, champ, &arg[j++], board[0]);
    }
  if (reference->func != NULL)
    reference->func(arg, champ, board);
}

void		load_instru(t_vm *vm,
			    t_champ *champ,
			    unsigned char board[2][MEM_SIZE])
{
  int		i;

  i = 0;
  while (op_tab[i].code != *champ->instru && op_tab[i].code != 0)
    i++;
  moving_PC(champ, board[0], 1);
  if (op_tab[i].code == 0)
    unknown_ope(champ, vm);
  else if (op_tab[i].code == 12)
    forking(vm, champ, board[0], 1);
  else if (op_tab[i].code == 15)
    forking(vm, champ, board[0], 0);
  else if (op_tab[i].code == 1)
    living(champ, board[0]);
  else if (op_tab[i].code == 9)
    zjump(champ, board[0], vm);
  else
    {
      if (vm->debug == 1)
	print_ope(op_tab[i].mnemonique);
      champ->ope.nbr_cycles = op_tab[i].nbr_cycles;
      champ->ope.nbr_args = op_tab[i].nbr_args;
      champ->ope.code = op_tab[i].code;
      get_jump(champ, board, &op_tab[i]);
    }
}
