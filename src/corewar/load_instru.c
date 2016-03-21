/*
** start_vm.c for corewar in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Mar  7 13:35:33 2016 Eric DESCHODT
** Last update Sat Mar 19 22:35:41 2016 Antoine Roig
*/

#include "corewar.h"

void		decal(char in[2],
		      t_champ *champ,
		      t_args *arg,
		      unsigned char *board)
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
  else
    mv = T_LAB;
  arg->type = mv;
  if (mv == T_DIR)
    mv = DIR_SIZE;
  else if (mv == T_IND)
    mv = IND_SIZE;
  arg->val = 0;
  tmp.full = 0;
  i = -1;
  while (++i < mv)
    {
      tmp.byte[4 - mv + i] = (*champ->instru);
      moving_PC(champ, board, 1);
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

void		get_jump(t_champ *champ,
			 unsigned char*board,
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
  moving_PC(champ, board, 1);
  while (--i >= 0 && j < reference->nbr_args)
    {
      if (c & (1u << i))
	in[(i % 2 == 1) ? 0 : 1] = 1;
      else
	in[(i % 2 == 1) ? 0 : 1] = 0;
      if (i % 2 == 0)
      	decal(in, champ, &arg[j++], board);
    }
  if (reference->func != NULL)
    reference->func(arg, champ);
}

void		moving_PC(t_champ *champ, unsigned char *board, int move)
{
  champ->cursor += move;
  if (champ->cursor == MEM_SIZE)
    {
      champ->cursor = 0;
      champ->instru = &board[0];
    }
  else if (champ->cursor == -1)
    {
      champ->cursor = MEM_SIZE - 1;
      champ->instru = &board[MEM_SIZE - 1];
    }
  else
    champ->instru += move;
}

void		load_instru(t_champ *champ,
			    unsigned char *board)
{
  int		i;

  i = 0;
  while (op_tab[i].code != *champ->instru && op_tab[i].code != 0)
    i++;
  moving_PC(champ, board, 1); 
  if (op_tab[i].code == 0)
    {
      my_printf("Ope inconnue %x\n", *(champ->instru - 1));
      champ->ope.nbr_cycles = 1;
      champ->ope.nbr_args = 1;
    }
  else if (op_tab[i].code == 11)
    sti(champ, board);
  else if (op_tab[i].code == 1)
    living(champ, board);
  else if (op_tab[i].code == 9)
    zjump(champ, board);
  else
    {
      champ->ope.nbr_cycles = op_tab[i].nbr_cycles;
      champ->ope.nbr_args = op_tab[i].nbr_args;
      get_jump(champ, board, &op_tab[i]);
    }
}
