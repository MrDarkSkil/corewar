/*
** op.c for  in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
**
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
**
** Started on  Thu Mar 17 12:57:29 2016 Eric DESCHODT
** Last update Thu Mar 24 13:52:17 2016 Eric DESCHODT
*/

#include "compilator.h"

op_t    op_tab[] =
  {
    {"live", 1, {T_DIR}, 1, 10, "alive", NULL, &live},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", NULL, &ld},
    {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", NULL, NULL},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", NULL, NULL},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", NULL, NULL},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
     6, 6, "et (and  r1, r2, r3   r1&r2 -> r3", NULL, NULL},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
     "ou  (or   r1, r2, r3   r1 | r2 -> r3", NULL, NULL},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
     "ou (xor  r1, r2, r3   r1^r2 -> r3", NULL, NULL},
    {"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", NULL, NULL},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
     "load index", NULL, NULL},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
     "store index", NULL, &sti},
    {"fork", 1, {T_DIR}, 12, 800, "fork", NULL, NULL},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", NULL, NULL},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
     "long load index", NULL, NULL},
    {"lfork", 1, {T_DIR}, 15, 1000, "long fork", NULL, NULL},
    {"aff", 1, {T_REG}, 16, 2, "aff", NULL, NULL},
    {0, 0, {0}, 0, 0, 0, NULL, NULL}
  };
