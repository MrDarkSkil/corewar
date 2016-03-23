/*
** start_vm.c for corewar in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Mar  7 13:35:33 2016 Eric DESCHODT
** Last update Wed Mar 23 22:13:54 2016 Eric DESCHODT
*/

#include "corewar.h"

void		unknown_ope(t_champ *champ, t_vm *vm)
{
  if (vm->debug == 1)
    {
      my_put_nbr_base(*(champ->instru - 1), "0123456789abcdef");
      my_putstr(" Unknown command\n");
    }
  champ->ope.nbr_cycles = 1;
}

void		print_ope(char *name)
{
  my_putstr(name);
  my_putchar('\n');
}
