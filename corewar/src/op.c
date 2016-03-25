/*
** op.c for  in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Thu Mar 17 12:57:29 2016 Eric DESCHODT
** Last update Fri Mar 25 13:35:02 2016 Eric DESCHODT
*/

#include "corewar.h"

op_t    op_tab[] =
  {
    {"live", 1, {T_DIR}, 1, 10, "alive", NULL, NULL},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", &ld, NULL},
    {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", &st, NULL},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", &add, NULL},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", &sub, NULL},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
     "et (and  r1, r2, r3   r1&r2 -> r3", &and, NULL},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
     "ou  (or   r1, r2, r3   r1 | r2 -> r3", &or, NULL},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
     "ou (xor  r1, r2, r3   r1^r2 -> r3", &xor, NULL},
    {"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", NULL, NULL},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
     "load index", &ldi, NULL},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
     "store index", &sti, NULL},
    {"fork", 1, {T_DIR}, 12, 800, "fork", NULL, NULL},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", &lld, NULL},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
     "long load index", &lldi, NULL},
    {"lfork", 1, {T_DIR}, 15, 1000, "long fork", NULL, NULL},
    {"aff", 1, {T_REG}, 16, 2, "aff", &aff, NULL},
    {0, 0, {0}, 0, 0, 0, NULL, NULL}
  };
