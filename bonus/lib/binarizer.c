/*
** tekcircle.c for  in /home/descho_e/year_2015_2016/I_graph/xorshape_2020
**
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
**
** Started on  Thu Dec 10 09:14:00 2015 Eric DESCHODT
** Last update Mon Feb 29 09:33:30 2016 Eric DESCHODT
*/

# include "libgraph.h"

void			elarg_text(t_bunny_pixelarray *pix,
				   t_bunny_position *pos,
				   t_bunny_position *size,
				   t_texture *tex)
{
  t_bunny_position	tmp;
  int			i;
  int			j;

  if (tex == NULL)
    return ;
  i = 0;
  tmp.y = pos->y;
  while (i < size->y)
    {
      j = 0;
      tmp.x = pos->x;
      while (j < size->x)
	{
	  tektranspa(pix, &tmp,
                   &tex->color[(int)(((float)i / (float)size->y) *
				     (float)(tex->height))]
                   [(int)(((float)j / (float)size->x) * (float)(tex->width))]);
	  tmp.x++;
	  j++;
	}
      tmp.y++;
      i++;
    }
}

t_texture		*pix_array_to_texture(t_bunny_pixelarray *pix)
{
  t_texture		*out;
  t_bunny_position	pos;

  if ((out = bunny_malloc(sizeof(t_texture))) == NULL)
    return (NULL);
  out->width = pix->clipable.clip_width;
  out->height = pix->clipable.clip_height;
  if ((out->color = bunny_malloc(sizeof(t_color *) * (out->height + 1))) == NULL)
    return (NULL);
  pos.y = 0;
  while (pos.y < out->height)
    {
      if ((out->color[pos.y] = bunny_malloc(4 * (out->width + 1))) == NULL)
	return (NULL);
      pos.x = 0;
      while (pos.x < out->width)
	{
	  out->color[pos.y][pos.x].full =
	    ((t_color *)pix->pixels)[pos.y * out->width + pos.x].full;
	  pos.x++;
	}
      pos.y++;
    }
  bunny_delete_clipable(&pix->clipable);
  return (out);
}

t_texture      		*load_bitmap(const char *file)
{
  t_bunny_pixelarray	*tmp;

  if ((tmp = bunny_load_pixelarray(file)) == NULL)
    return (NULL);
  return (pix_array_to_texture(tmp));
}

void			put_bmp(t_texture *bmp,
				t_bunny_pixelarray *pix,
				t_bunny_position *pos)
{
  t_bunny_position	tmp;
  int			i;
  int			j;

  if (bmp == NULL)
    return ;
  i = 0;
  tmp.y = pos->y;
  while (i < bmp->height)
    {
      j = 0;
      tmp.x = pos->x;
      while (j < bmp->width)
	{
	  tektranspa(pix, &tmp, &bmp->color[i][j]);
	  tmp.x++;
	  j++;
	}
      tmp.y++;
      i++;
    }
}
