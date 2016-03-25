/*
** op.c for  in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
**
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
**
** Started on  Thu Mar 17 12:57:29 2016 Eric DESCHODT
** Last update Fri Mar 25 11:57:50 2016 Eric DESCHODT
*/

#include "compilator.h"

op_t    op_tab[] =
  {
    {"live", 1, {T_DIR}, 1, 10, "alive", NULL, &live},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", NULL, &ld},
    {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", NULL, &ld},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", NULL, &and},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", NULL, &and},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
     6, 6, "et (and  r1, r2, r3   r1&r2 -> r3", NULL, &and},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
     "ou  (or   r1, r2, r3   r1 | r2 -> r3", NULL, &and},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
     "ou (xor  r1, r2, r3   r1^r2 -> r3", NULL, &and},
    {"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", NULL, &zjump},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
     "load index", NULL, &ldi},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
     "store index", NULL, &sti},
    {"fork", 1, {T_DIR}, 12, 800, "fork", NULL, &zjump},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", NULL, &ld},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
     "long load index", NULL, &ldi},
    {"lfork", 1, {T_DIR}, 15, 1000, "long fork", NULL, &zjump},
    {"aff", 1, {T_REG}, 16, 2, "aff", NULL, &aff},
    {0, 0, {0}, 0, 0, 0, NULL, NULL}
  };
