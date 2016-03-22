/*
** corewar.h for  in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Mar  7 12:59:17 2016 Eric DESCHODT
** Last update Tue Mar 22 15:04:28 2016 Antoine Roig
*/

#ifndef COREWAR_H_
# define COREWAR_H_

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "op.h"
# include "myprintf.h"
# include "get_next_line.h"

typedef struct		s_champ
{
  char			reg[REG_NUMBER][REG_SIZE];
  int			id;
  unsigned char		*instru;
  char                  *name;
  unsigned char		*start;
  int			cycle;
  int			cursor;
  int			size;
  int			alive;
  op_t			ope;
  char			carry;
  struct s_champ	*next;
  struct s_champ	*prev;
}			t_champ;

typedef struct		s_vm
{
  t_champ		*begin;
  t_champ		*end;
  int			nb;
  int                   dump;
}			t_vm;

typedef struct          s_list
{
  char                  *arg;
  struct s_list         *next;
  struct s_list         *prev;
}        t_list;

typedef struct          s_dlist
{
  t_list                *begin;
  t_list                *end;
  int                   size;
}       t_dlist;

typedef struct          s_lcmd
{
  char                  *name;
  int                   a;
  int                   id;
}                       t_lcmd;

typedef struct		s_decal_nb
{
  int			decal;
  int			nb;
}			t_decal_nb;

void			my_puterror(char *str);

char			*my_memeset(char *str, char c, int len);

void			*xmalloc(int size);

t_vm			*new_vm(t_vm *vm);

void			launch_vm(t_vm *vm, int nb_champ);

int			start_vm(t_vm *vm, unsigned char *board);

void			find_living_champion(int result, t_champ *champ);

void			living(t_champ *champ, unsigned char *board);

void			load_instru(t_vm *vm, t_champ *champ, unsigned char *board);

void			revert_endian(int *nb);

void			print_info(header_t *head);

int			convert_reg(char *nbr);

void			printboard(unsigned char *board);

/* VM fonctions */

int			sti(t_args *arg, void *champ);
int			forking(t_vm *vm, t_champ *champ, unsigned char *board);
int			ld(t_args *arg, void *champ);
int			add(t_args *arg, void *champ);
int			or(t_args *arg, void *champ);
int			xor(t_args *arg, void *champ);
int			and(t_args *arg, void *champ);
int			sub(t_args *arg, void *champ);
int			zjump(t_champ *champ,
			      unsigned char *board);
void			moving_PC(t_champ *champ,
				  unsigned char *board,
				  int move);
void			init_alive(t_vm *vm);
void			swap_carry(t_champ *champ);

/* Lists */

int			create_champ(t_champ *new_elem,
				     t_lcmd *info,
				     unsigned char *board);

void			find_champ(t_dlist *list,
				   t_vm *vm,
				   unsigned char *board);

void			find_dump(t_dlist *list,
				  t_vm *vm);

void			info_champ(t_dlist *list,
				   int i,
				   t_lcmd *info);

void			fill_list(t_dlist *list,
				  char **av);

void			fill_new(t_champ *new,
				 t_champ *champ);

void			add_list_end_vm(t_vm *vm,
					t_champ *champ);

t_vm			*new_vm(t_vm *vm);

void			show_list_vm(t_vm *vm);

void                    *xmalloc(int);

t_dlist                 *new_list(t_dlist*);

void                    show_list(t_dlist *);

void                    clear_list(t_dlist *list);

void                    rev_list(t_dlist * list);

/* add_list */

void                    add_list_end(t_dlist *, char *);
void                    add_list_begin(t_dlist *, int);
void                    add_list_somewhere(t_dlist *, int, int);
void                    add_list_somewhere2(t_dlist *, t_list *, int);

/* pop_list */

t_list                  *pop_list_begin(t_dlist *);
t_list                  *pop_list_end(t_dlist *);
t_list                  *pop_list_somewhere(t_dlist *, int);
t_list                  *pop_list_somewhere2(t_dlist *, int);

void    fill_new(t_champ *new, t_champ *champ);
void    fill_new_fork(t_champ *new, t_champ *champ, int nb, unsigned char *board);
void    add_list_begin_vm(t_vm *list, t_champ *champ);
void    add_vm_somewhere2(t_vm *vm, t_champ *new, int pos);
void    add_vm_somewhere(t_vm *vm, t_champ *champ, t_decal_nb decal_nb, unsigned char *board);
void	add_forking(t_vm *vm, t_champ *champ, int nb, unsigned char* board);
int     my_strcmp(char *s1, char *s2);

#endif /* !COREWAR_H */
