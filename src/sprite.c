/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:39:58 by mflor             #+#    #+#             */
/*   Updated: 2021/03/11 02:50:40 by mflor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		countsprites(t_cub *mycub)
{
	int a;
	int b;

	mycub->numsprites = 0;
	a = -1;
	while (mycub->worldmap[++a])
	{
		b = 0;
		while (mycub->worldmap[a][b])
		{
			if (mycub->worldmap[a][b] == '2')
				mycub->numsprites++;
			b++;
		}
	}
}

static void	sortsprites(t_cub *mycub)
{
	int			i;
	int			j;
	t_sprite	temp;

	i = -1;
	while (++i < mycub->numsprites)
	{
		j = mycub->numsprites;
		while (j > i)
		{
			if (mycub->sprite[j].dist > mycub->sprite[j - 1].dist)
			{
				temp = mycub->sprite[j];
				mycub->sprite[j] = mycub->sprite[j - 1];
				mycub->sprite[j - 1] = temp;
			}
			j--;
		}
	}
}

static void	wsprite3(t_cub *mycub, t_sc *sc)
{
	sc->transx = sc->invd * (mycub->dir->diry *
			sc->sprx - mycub->dir->dirx * sc->spry);
	sc->transy = sc->invd * (-mycub->planey
			* sc->sprx + mycub->planex * sc->spry);
	sc->sprscrx = (int)((mycub->karta.x / 2) * (1 + sc->transx / sc->transy));
	sc->sprh = abs((int)(mycub->karta.y / (sc->transy)));
	sc->drsty = -sc->sprh / 2 + mycub->karta.y / 2;
	if (sc->drsty < 0)
		sc->drsty = 0;
	sc->drendy = sc->sprh / 2 + mycub->karta.y / 2;
	if (sc->drendy >= mycub->karta.y)
		sc->drendy = mycub->karta.y - 1;
	sc->sprw = abs((int)(mycub->karta.y / (sc->transy)));
	sc->drstx = -sc->sprw / 2 + sc->sprscrx;
	if (sc->drstx < 0)
		sc->drstx = 0;
	sc->drendx = sc->sprw / 2 + sc->sprscrx;
	if (sc->drendx >= mycub->karta.x)
		sc->drendx = mycub->karta.x - 1;
}

static void	wsprite2(t_cub *mycub, double *zbuffer, t_sc sc)
{
	int y;

	wsprite3(mycub, &sc);
	sc.stripe = sc.drstx - 1;
	while (++sc.stripe < sc.drendx)
	{
		sc.texx = (int)(256 * (sc.stripe - (-sc.sprw / 2 + sc.sprscrx))
				* mycub->st->w / sc.sprw) / 256;
		if (sc.transy > 0 && sc.stripe > 0 &&
				sc.stripe < mycub->karta.x && sc.transy < zbuffer[sc.stripe])
			y = sc.drsty;
		while (y < sc.drendy)
		{
			sc.d = (y) * 256 - mycub->karta.y * 128 + sc.sprh * 128;
			sc.texy = ((sc.d * mycub->st->h) / sc.sprh) / 256;
			sc.color = get_color(mycub->st, sc.texx, sc.texy);
			if ((sc.color & (BL)) != 0)
				my_mlx_pixel_put(mycub->img, sc.stripe, y, sc.color);
			y++;
		}
	}
}

void		wsprite(t_cub *mycub, double *zbuffer)
{
	t_sc	sc;
	int		spriteorder[mycub->numsprites];
	int		i;

	i = -1;
	while (++i < mycub->numsprites)
	{
		spriteorder[i] = i;
		mycub->sprite[i].dist = ((mycub->plr->posx - mycub->sprite[i].x)
				* (mycub->plr->posx - mycub->sprite[i].x)
				+ (mycub->plr->posy - mycub->sprite[i].y)
				* (mycub->plr->posy - mycub->sprite[i].y));
	}
	sortsprites(mycub);
	i = -1;
	while (++i < mycub->numsprites)
	{
		sc.sprx = mycub->sprite[spriteorder[i]].x - mycub->plr->posx;
		sc.spry = mycub->sprite[spriteorder[i]].y - mycub->plr->posy;
		sc.invd = 1.0 / (mycub->planex * mycub->dir->diry
				- mycub->dir->dirx * mycub->planey);
		wsprite2(mycub, zbuffer, sc);
	}
}
