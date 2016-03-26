/*
** libtekgui.h for  in /home/descho_e/year_2015_2016/I_graph/gfx_tekgui
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Tue Feb  2 13:19:12 2016 Eric DESCHODT
** Last update Sat Mar 26 09:32:26 2016 Eric DESCHODT
*/

#ifndef			LIBGRAPH_H_
# define		LIBGRAPH_H_

# include		"lapin.h"

typedef struct          s_bmp
{
  short int             magicnumber;
  unsigned int          totalsize;
  unsigned int          unused;
  unsigned int          position;
  unsigned int          head_size;
  unsigned int          width;
  unsigned int          height;
  short int             plans_nb;
  short int             bitbypixel;
  unsigned int          compression;
  unsigned int          size_octet;
  unsigned int          pixelwidth;
  unsigned int          pixelheight;
  unsigned int          nb_color_pal;
  unsigned int          impocolo;
}__attribute__((packed))t_bmp ;

typedef struct          s_texture
{
  int                   width;
  int                   height;
  t_color               **color;
}                       t_texture;

typedef struct          s_police
{
  char                  *str;
  t_bunny_position      pos;
  float                 ratio;
  t_color               color;
}                       t_police;

void                    elarg_text(t_bunny_pixelarray *pix,
                                   t_bunny_position *pos,
                                   t_bunny_position *size,
                                   t_texture *tex);

t_texture               *load_bitmap(const char *file);

void                    put_bmp(t_texture *bmp,
                                t_bunny_pixelarray *pix,
                                t_bunny_position *pos);

void                    fill(t_bunny_pixelarray *pix,
                             t_color *color);

char                    *get_chmp(char *chmp,
                                  t_bunny_ini *file,
                                  int i);

void                    tekpixel(t_bunny_pixelarray *pix,
                                 t_bunny_position *pos,
                                 t_color *color);

void                    tektranspa(t_bunny_pixelarray *pix,
                                   t_bunny_position *pos,
                                   t_color *color);

# endif /* LIBGRAPH_H_ */

