/*
** op.h for  in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
**
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
**
** Started on  Thu Mar 17 12:50:43 2016 Eric DESCHODT
** Last update Sat Mar 26 11:23:13 2016 Eric DESCHODT
*/

#ifndef OP_H_
# define OP_H_

# define MEM_SIZE               (6*1024)
# define IDX_MOD                512
# define MAX_ARGS_NUMBER        4

# define COMMENT_CHAR           '#'
# define LABEL_CHAR             ':'
# define DIRECT_CHAR            '%'
# define SEPARATOR_CHAR         ','
# define LABEL_CHARS		"abcdefghijklmnopqrstuvwxyz_0123456789"
# define NAME_CMD_STRING	".name"
# define COMMENT_CMD_STRING	".comment"

# define REG_NUMBER		16

typedef char			args_type_t;

# define T_REG			1
# define T_DIR			2
# define T_IND			4
# define T_LAB			8

typedef union			u_byte
{
  unsigned char			byte[4];
  int				full;
}				t_byte;

typedef struct			s_args
{
  args_type_t			type;
  int				val;
}				t_args;

typedef struct			op_s
{
  char				*mnemonique;
  char				nbr_args;
  args_type_t			type[MAX_ARGS_NUMBER];
  char				code;
  int				nbr_cycles;
  char				*comment;
  int				(*func)(t_args *, void *, unsigned char [2][MEM_SIZE]);
  int				(*wfunc)(char *, int, char);
}				op_t;

# define IND_SIZE		2
# define REG_SIZE		4
# define DIR_SIZE		REG_SIZE

# define PROG_NAME_LENGTH       128
# define COMMENT_LENGTH         2048
# define COREWAR_EXEC_MAGIC     0xea83f3

extern op_t			op_tab[];

typedef struct			header_s
{
   int				magic;
   char				prog_name[PROG_NAME_LENGTH + 1];
   int				prog_size;
   char				comment[COMMENT_LENGTH + 1];
}				header_t;

# define CYCLE_TO_DIE		1536
# define CYCLE_DELTA		5
# define NBR_LIVE		40

#endif /* !OP_H_ */
