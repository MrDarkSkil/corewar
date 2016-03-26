/*
** tekpixel.c for  in /home/descho_e/year_2015_2016/I_graph/tekadventure/tcore
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Sun Jan 31 14:41:41 2016 Eric DESCHODT
** Last update Sat Mar 26 10:45:00 2016 Eric DESCHODT
*/

#include "libgraph.h"

void			tekpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 t_color *color)
{
  if (pos->x < pix->clipable.clip_width &&
      pos->y < pix->clipable.clip_height &&
      pos->x >= 0 && pos->y >= 0)
    {
      ((t_color *)pix->pixels)[pos->x + pix->clipable.clip_width * pos->y]
      	= *color;
    }
}

void			tektranspa(t_bunny_pixelarray *pix,
				   t_bunny_position *pos,
				   t_color *color)
{
  t_color	prev;

  if (color->argb[3] == 255)
    {
      tekpixel(pix, pos, color);
      return;
    }
  if (pos->x < pix->clipable.clip_width &&
      pos->y < pix->clipable.clip_height &&
      pos->x >= 0 && pos->y >= 0)
    {
      prev =
	((t_color *)pix->pixels)[pos->x + pix->clipable.clip_width * pos->y];

      prev.argb[0] = (float)prev.argb[0] * ((255 -
					     (float)color->argb[3]) / 255)
	+ ((float)color->argb[0] * ((float)color->argb[3] / 255));
      prev.argb[1] = (float)prev.argb[1] * ((255 -
					     (float)color->argb[3]) / 255)
	+ ((float)color->argb[1] * ((float)color->argb[3] / 255));
      prev.argb[2] = (float)prev.argb[2] * ((255 -
					     (float)color->argb[3]) / 255)
	+ ((float)color->argb[2] * ((float)color->argb[3] / 255));
      prev.argb[3] = 255;
      ((t_color *)pix->pixels)[pos->x + pix->clipable.clip_width * pos->y]
	= prev;
    }
}
