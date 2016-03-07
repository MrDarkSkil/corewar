/*
** my.h for  in /home/descho_e/Piscine/Piscine_C_J09/include
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Thu Oct  8 09:07:44 2015 Eric DESCHODT
** Last update Wed Feb 17 09:24:19 2016 Eric DESCHODT
*/

#ifndef MY_PRINTF_
# define MY_PRINTF_

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct  s_format_id
{
  int           flag_minus;
  int           flag_zero;
  int           flag_plus;
  int           flag_blank;
  int           flag_hashtag;
  int           min_field;
  int           max_field;
  char          argument;
}t_format_id;

int		my_getnbr(char *);
int		my_showstr(char *);
int             my_printf(const char *, ...);
void		my_put_float(long double, int);
int		my_put_nbr(int);
void		my_put_nbr_base(unsigned int, char *);
int             find_flags(t_format_id *, char);
int             init_stock(char *, t_format_id *);
int             decypher_flags(t_format_id *, va_list *);
int             get_flag(int, int, const char *, va_list *);
void            printf_float(t_format_id *, va_list *);
int		my_putchar(char);
int		my_putstr(char *);
int		my_strlen(char *);
char		*my_strcat(char *, char *);
char		*convert_base(char *, char *, char *);
int		my_getnbr_base(char *, char *);
char		*my_revstr(char *);
void            my_memset(char *, int, char);
char            *int_in_str(int, int);
void            printf_decimal(t_format_id *, va_list *);
void            printf_octal(t_format_id *, va_list *);
void            printf_hexa(t_format_id *, va_list *);
void            printf_pointer(va_list *);
void            printf_binary(va_list *);
void            printf_unddec(va_list *);
int             decypher_flags(t_format_id *, va_list *);
void            first_init_stock(t_format_id *);
void		print_noflags(int *, char *);

#endif /* !MY_PRINTF_ */
