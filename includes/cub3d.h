/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflor <mflor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 02:36:13 by mflor             #+#    #+#             */
/*   Updated: 2021/03/11 02:36:30 by mflor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_CUB3D_H
# define CUB3D_CUB3D_H
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "cub3d.h"
# include "math.h"
# include "../minilibx_mms/main.h"
# include "../libft/libft.h"
# define MS 0.2
# define RS 0.1
# define TW 64
# define TH 64
# define CH "012SNEW"
# define BL 0x00FFFFFF

typedef struct	s_plr
{
	double	posx;
	double	posy;
}				t_plr;

typedef struct	s_dir
{
	double dirx;
	double diry;
}				t_dir;

typedef struct	s_vars {
	void	*mx;
	void	*wn;
}				t_vs;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		end;
}				t_data;

typedef struct	s_karta
{
	int	x;
	int	y;
}				t_karta;

typedef struct	s_txt
{
	void	*img;
	void	*addr;
	int		bpp;
	int		ll;
	int		end;
	int		w;
	int		h;
}				t_txt;

typedef struct	s_sprite
{
	double	x;
	double	y;
	double	dist;
}				t_sprite;

typedef struct	s_col
{
	int r;
	int g;
	int b;
	int cur;
}				t_col;

typedef struct	s_dr
{
	double	camerax;
	double	raydirx;
	double	raydiry;
	double	sidedistx;
	double	sidedisty;
	double	ddistx;
	double	ddisty;
	double	pwdist;
	int		stepx;
	int		stepy;
	int		lheight;
	int		hit;
	int		side;
	int		color;
	double	wallx;
	int		dstart;
	int		dend;
	int		texx;
	int		texy;
	int		mapx;
	int		mapy;
	double	tpos;
	double	step;
}				t_dr;

typedef struct	s_sc
{
	double	sprx;
	double	spry;
	double	invd;
	double	transx;
	double	transy;
	int		sprscrx;
	int		sprh;
	int		sprw;
	int		drsty;
	int		drstx;
	int		drendx;
	int		drendy;
	int		stripe;
	int		texx;
	int		texy;
	int		d;
	int		color;

}				t_sc;

typedef struct	s_cub
{
	double		planex;
	double		planey;
	double		odirx;
	double		oplanex;
	t_dir		*dir;
	t_plr		*plr;
	t_vs		*vs;
	t_data		*img;
	t_karta		karta;
	char		*no;
	char		*ea;
	char		*we;
	char		*so;
	char		*s;
	char		**worldmap;
	t_txt		*not;
	t_txt		*eat;
	t_txt		*wet;
	t_txt		*sot;
	t_txt		*tot;
	t_txt		*st;
	int			numsprites;
	int			carg;
	t_sprite	*sprite;
	t_col		f;
	t_col		c;

}				t_cub;

int				parser(char **map, t_cub *mycub);
void			draw_karta(t_cub *mycub);
int				keypress(int keycode, t_cub *mycub);
void			wsprite(t_cub *mycub, double *zbuffer);
int				check_zero(char **wmap, int a, int b);
int				surround(char c, char *s);
void			countsprites(t_cub *mycub);
int				ft_error(int p);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				get_color(t_txt *txt, int x, int y);
void			txts(t_cub *mycub);
int				keypress(int keycode, t_cub *mycub);
int				ft_sshot(t_cub *mycub);
int				ft_close(int p);
int				checkname(char *nazv);
int				checkname2(char *nazv, char *name);
int				hmmaloc(char *karta);
void			left(t_cub *mycub);
void			right(t_cub *mycub);
int				wmapmalloc(char **map);
int				create_rgb(int r, int g, int b);
int				checkmap(t_cub *mycub);
void			copymap(t_cub *mycub, char **map, int count, int a);
int				resolution(t_cub *mycub, char *map, int b);
int				check_color(t_col *c);

#endif
