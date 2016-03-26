/*
** winning.c for  in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Fri Mar 25 14:42:37 2016 Eric DESCHODT
** Last update Fri Mar 25 14:55:07 2016 Eric DESCHODT
*/

#include "corewar.h"

void	winning(t_vm *vm)
{
  if (vm->begin != NULL)
    {
      my_putstr("Le champion ");
      my_put_nbr(vm->begin->id);
      my_putstr(" (");
      my_putstr(vm->begin->name);
      my_putstr(") a gagné\n");
    }
}
