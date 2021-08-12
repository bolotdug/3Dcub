/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_karta.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 02:24:55 by mflor             #+#    #+#             */
/*   Updated: 2021/03/11 02:53:22 by mflor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	countdr(t_dr *dr, t_cub *mycub, int x)
{
	dr->camerax = 2 * x / (double)mycub->karta.x - 1;
	dr->raydirx = mycub->dir->dirx + mycub->planex * dr->camerax;
	dr->raydiry = mycub->dir->diry + mycub->planey * dr->camerax;
	dr->mapx = (int)(mycub->plr->posx);
	dr->mapy = (int)(mycub->plr->posy);
	if (dr->raydiry == 0)
		dr->ddistx = 0;
	else if (dr->raydiry != 0)
		dr->ddistx = (dr->raydirx == 0) ? 1 : fabs(1 / dr->raydirx);
	if (dr->raydirx == 0)
		dr->ddisty = 0;
	else if (dr->raydirx != 0)
		dr->ddisty = (dr->raydiry == 0) ? 1 : fabs(1 / dr->raydiry);
	dr->hit = 0;
	dr->stepx = (dr->raydirx < 0) ? -1 : 1;
	if (dr->raydirx < 0)
		dr->sidedistx = (mycub->plr->posx - dr->mapx) * dr->ddistx;
	else
		dr->sidedistx = (dr->mapx + 1.0 - mycub->plr->posx) * dr->ddistx;
}

void	countdr1(t_dr *dr, t_cub *mycub)
{
	dr->stepy = (dr->raydiry < 0) ? -1 : 1;
	if (dr->raydiry < 0)
		dr->sidedisty = (mycub->plr->posy - dr->mapy) * dr->ddisty;
	else
		dr->sidedisty = (dr->mapy + 1.0 - mycub->plr->posy) * dr->ddisty;
	while (dr->hit == 0)
	{
		if (dr->sidedistx < dr->sidedisty)
		{
			dr->sidedistx += dr->ddistx;
			dr->mapx += dr->stepx;
			dr->side = 0;
		}
		else
		{
			dr->sidedisty += dr->ddisty;
			dr->mapy += dr->stepy;
			dr->side = 1;
		}
		if (mycub->worldmap[dr->mapx][dr->mapy] == '1')
			dr->hit = 1;
	}
}

void	countdr2(t_dr *dr, t_cub *mycub)
{
	if (dr->side == 0)
		dr->pwdist = (dr->mapx - mycub->plr->posx
				+ (double)(1 - dr->stepx) / 2) / dr->raydirx;
	else
		dr->pwdist = (dr->mapy - mycub->plr->posy
				+ (double)(1 - dr->stepy) / 2) / dr->raydiry;
	dr->lheight = (int)(mycub->karta.y / dr->pwdist);
	dr->dstart = -dr->lheight / 2 + mycub->karta.y / 2;
	if (dr->dstart < 0)
		dr->dstart = 0;
	dr->dend = dr->lheight / 2 + mycub->karta.y / 2;
	if (dr->dend >= mycub->karta.y)
		dr->dend = mycub->karta.y - 1;
	if (dr->side == 0)
		dr->wallx = mycub->plr->posy + dr->pwdist * dr->raydiry;
	else
		dr->wallx = mycub->plr->posx + dr->pwdist * dr->raydirx;
	dr->wallx -= floor((dr->wallx));
	dr->texx = (int)(dr->wallx * (double)(TW));
	if ((dr->side == 0 && dr->raydirx > 0)
			|| (dr->side == 1 && dr->raydiry < 0))
		dr->texx = TW - dr->texx - 1;
	dr->step = 1.0 * TH / dr->lheight;
	dr->tpos = (dr->dstart - mycub->karta.y
			/ 2.0 + dr->lheight / 2.0) * dr->step;
}

void	verline(t_dr *dr, t_cub *mycub, int x)
{
	int y;

	y = dr->dstart - 1;
	while (++y < dr->dend)
	{
		dr->texy = (int)dr->tpos % (TH - 1);
		dr->tpos += dr->step;
		if (dr->side == 0 && mycub->plr->posx > mycub->plr->posx + dr->raydirx)
			mycub->tot = mycub->not;
		if (dr->side == 0 && mycub->plr->posx < mycub->plr->posx + dr->raydirx)
			mycub->tot = mycub->sot;
		if (dr->side == 1 && mycub->plr->posy > mycub->plr->posy + dr->raydiry)
			mycub->tot = mycub->wet;
		if (dr->side == 1 && mycub->plr->posy < mycub->plr->posy + dr->raydiry)
			mycub->tot = mycub->eat;
		dr->color = get_color(mycub->tot, dr->texx, dr->texy);
		my_mlx_pixel_put(mycub->img, x, y, dr->color);
	}
	y = dr->dend;
	while (y++ < mycub->karta.y - 1)
		my_mlx_pixel_put(mycub->img, x, y, mycub->f.cur);
	y = -1;
	while (++y <= dr->dstart)
		my_mlx_pixel_put(mycub->img, x, y, mycub->c.cur);
}

void	draw_karta(t_cub *mycub)
{
	t_dr	dr;
	double	*zbuffer;
	int		x;

	x = -1;
	if (!(zbuffer = malloc(sizeof(double) * mycub->karta.x + sizeof(double))))
		ft_error(-1);
	while (++x < mycub->karta.x)
	{
		countdr(&dr, mycub, x);
		countdr1(&dr, mycub);
		countdr2(&dr, mycub);
		verline(&dr, mycub, x);
		zbuffer[x] = dr.pwdist;
	}
	wsprite(mycub, zbuffer);
	free(zbuffer);
}
