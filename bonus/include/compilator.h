/*
** comilator.h for compilator in /home/hubert_i/rendu/2015/coreware/src/asm
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Thu Mar 17 17:53:01 2016 Léo Hubert
** Last update Sat Mar 26 08:33:01 2016 Eric DESCHODT
*/

#ifndef COMPILATOR_H_
# define COMPILATOR_H_

# include	<sys/stat.h>
# include	<fcntl.h>
# include	<stdlib.h>
# include	"op.h"
# include	"get_next_line.h"
# include	"my.h"

typedef struct	s_asm
{
  char		*ins;
  char		*param;
  int		first;
  struct s_asm	*next;
  struct s_asm	*prev;
}		t_asm;

typedef struct	s_arg
{
  int		value;
  int		size;
}		t_arg;

short int       swap_shnbr(short int nbr);
void            *xmalloc(int size);
char		*take_begin(char	*str,
			    char	c);
char		*parse_name(char	*str);
char		*parse_comment(char	*str);
char		*get_name(char		*str);
char		*get_comment(char	*str);
int		swap_nbr(int		nbr);
int		my_strlen(char		*str);
char		*my_strfusion(char	*str,
			      char	*str2);
int		create_cor(char		*file);
char		*take_after(char	*str,
			    char	c);
char		*take_begin(char	*str,
			    char	c);
int		my_strcmp(char		*s1,
			  char		*s2);
int		my_strcmp_2(char	*s1,
			    char	*s2);
int		create_header(int	fd,
			      int	fdwrite);
t_asm		*add_action(t_asm	*list,
			    char	*ins,
			    char	*param);
int		write_instructions(int	fd,
				   int	fdwrite);
char		*remove_space(char	*str);
int             agregate(char *nb, int *i, char *tmp);
int		instructions_file(int fdwrite, t_asm *my_asm);
int             get_args(t_arg *arg, char *nb, int *i, char *tmp);
int             live(char *param, int fdwrite, char code);
int             sti(char *param, int fdwrite, char code);
int             ldi(char *param, int fdwrite, char code);
int             ld(char *param, int fdwrite, char code);
int             and(char *param, int fdwrite, char code);
int             zjump(char *param, int fdwrite, char code);
int             aff(char *param, int fdwrite, char code);
int		countword(char *str, char caract);
int		current(char *str, char caract);
char		**my_str_to_wordtab(char *str, char caract);
int		my_putchar_error(char c);
int		my_putstr_error(char *str);
int		my_putnbr_error(int nb);
int		error_line(int line);
int		init_ptIns(int (*ptIns[17])(char *param));
int		check_param(char *ins, char *param);
int		check_arg(char *str);
int		count_cee(char **tab);
int		is_num(char *nbr);
int		all_space(char *str);
int		write_size(int fdwrite, int size);
char		*my_strdup(char *str);
char		*parse_action(char *str, int select);
char		*remove_all_space(char *str);
int		check_fork(char *param);
int		check_lld(char *param);
int		check_lldi(char *param);
int		check_lfork(char *param);
int		check_aff(char *param);
int		check_sti(char *param);
int		check_fork(char *param);
int		check_lld(char *param);
int		check_lldi(char *param);
int		check_lfork(char *param);
int		check_and(char *param);
int		check_or(char *param);
int		check_xor(char *param);
int		check_zjmp(char *param);
int		check_ldi(char *param);
int		check_live(char *param);
int		check_ld(char *param);
int		check_st(char *param);
int		check_add(char *param);
int		check_sub(char *param);


#endif /* !COMPILATOR_H_ */
