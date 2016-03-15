/*
** start_vm.c for corewar in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Mar  7 13:35:33 2016 Eric DESCHODT
** Last update Tue Mar 15 18:05:40 2016 Eric DESCHODT
*/

#include "corewar.h"

void		init_alive(t_vm *vm)
{
  int		i;
  t_champ	*tmp;

  tmp = vm->begin;
  i = 0;
  while (i < vm->nb)
    {
      tmp->alive = 0;
      tmp = tmp->next;
      i++;
    }
}

void		decal(char in[2], t_champ *champ)
{
  int		mv;

  if (in[0] == 0 && in[1] == 1)
    mv = T_REG;
  else if (in[0] == 1 && in[1] == 0)
    mv = T_DIR;
  else if (in[0] == 1 && in[1] == 1)
    mv = T_IND;
  champ->instru += mv;
  champ->cursor += mv;
}

void		get_jump(t_champ *champ,
			 unsigned char *board,
			 op_t *reference)
{
  int		i;
  int		j;
  char		c;
  char		in[2];

  (void)board;
  c = *champ->instru;
  champ->instru++;
  champ->cursor++;
  i = 7;
  j = 0;
  while (i >= 0 && j < reference->nbr_args)
    {
      if (c & (1u << i))
	in[(i % 2 == 1) ? 0 : 1] = 1;
      else
	in[(i % 2 == 1) ? 0 : 1] = 0;
      if (i % 2 == 0)
	{
	  decal(in, champ);
	  j++;
	}
      i--;
    }
}
void		load_instru(t_champ *champ,
			    unsigned char *board)
{
  int		i;

  i = 0;
  while (op_tab[i].code != *champ->instru && op_tab[i].code != 0)
    i++;
  if (i == 16)
    {
      champ->ope.nbr_cycles = 1;
      champ->ope.nbr_args = 1;
      champ->cursor += 1;
      champ->instru += 1;
    }
  else
    {
      champ->ope.nbr_cycles = op_tab[i].nbr_cycles;
      champ->ope.nbr_args = op_tab[i].nbr_args;
      my_printf("commande reconnue : %s qui prend %d cycles\n",
		op_tab[i].mnemonique, op_tab[i].nbr_cycles);
      if (op_tab[i].code != 0x01 && op_tab[i].code != 0x09
	  && op_tab[i].code != 0x0c && op_tab[i].code != 0x0f)
	{
	  champ->instru += 1;
	  champ->cursor += 1;
	  get_jump(champ, board, &op_tab[i]);
	}
      else if (op_tab[i].code == 0x01)
	{
	  champ->instru += 6;
	  champ->cursor += 6;
	}
      else
	{
	  champ->instru += 1;
	  champ->cursor += 1;
	}
    }
}

int		execute_champ(t_champ *champ,
			      unsigned char *board)
{
  if (champ->cycle == 0)
    load_instru(champ, board);
  if (champ->cycle == champ->ope.nbr_cycles)
    champ->cycle = 0;
  else
    champ->cycle++;
  /* my_printf("cycle = %d\n cursor = %d\n", champ->cycle, champ->cursor); */
  if (champ->cursor == (champ->size))
    {
      my_printf("==== RESET ====\n");
      champ->instru -= (champ->size);
      champ->cursor = 0;
    }
  return (0);
}

int		all_champ(t_vm *vm,
			  unsigned char *board)
{
  int		i;
  t_champ	*tmp;

  i = 0;
  tmp = vm->begin;
  while (i < vm->nb)
    {
      execute_champ(tmp, board);
      tmp = tmp->next;
      i++;
    }
  return (0);
}

int		start_vm(t_vm *vm,
			 unsigned char *board)
{
  int		end;
  int		start;

  end = CYCLE_TO_DIE;
  while (end > 0)
    {
      start = end;
      init_alive(vm);
      while (start > 0)
	{
	  all_champ(vm, board);
	  start--;
	}
      end -= CYCLE_DELTA;
    }
  return (0);
}
