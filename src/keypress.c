/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflor <mflor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:11:57 by mflor             #+#    #+#             */
/*   Updated: 2021/03/11 04:38:21 by mflor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../minilibx_mms/main.h"
#include "../includes/cub3d.h"

void	rright(t_cub *mycub)
{
	mycub->odirx = mycub->dir->dirx;
	mycub->dir->dirx = mycub->dir->dirx * cos(-RS) -
		mycub->dir->diry * sin(-RS);
	mycub->dir->diry = mycub->odirx * sin(-RS) + mycub->dir->diry * cos(-RS);
	mycub->oplanex = mycub->planex;
	mycub->planex = mycub->planex * cos(-RS) - mycub->planey * sin(-RS);
	mycub->planey = mycub->oplanex * sin(-RS) + mycub->planey * cos(-RS);
}

void	lleft(t_cub *mycub)
{
	mycub->odirx = mycub->dir->dirx;
	mycub->dir->dirx = mycub->dir->dirx * cos(RS) - mycub->dir->diry * sin(RS);
	mycub->dir->diry = mycub->odirx * sin(RS) + mycub->dir->diry * cos(RS);
	mycub->oplanex = mycub->planex;
	mycub->planex = mycub->planex * cos(RS) - mycub->planey * sin(RS);
	mycub->planey = mycub->oplanex * sin(RS) + mycub->planey * cos(RS);
}

void	key123(t_cub *mycub)
{
	int a;
	int b;

	a = (int)(mycub->plr->posx - mycub->planex * MS);
	b = (int)(mycub->plr->posy - mycub->planey * MS);
	if (mycub->worldmap[a][(int)(mycub->plr->posy)] != '1')
		mycub->plr->posx -= mycub->planex * MS;
	if (mycub->worldmap[(int)(mycub->plr->posx)][b] != '1')
		mycub->plr->posy -= mycub->planey * MS;
}

void	key124(t_cub *mycub)
{
	int a;
	int b;

	a = (int)(mycub->plr->posx + mycub->planex * MS);
	b = (int)(mycub->plr->posy + mycub->planey * MS);
	if (mycub->worldmap[a][(int)(mycub->plr->posy)] != '1')
		mycub->plr->posx += mycub->planex * MS;
	if (mycub->worldmap[(int)(mycub->plr->posx)][b] != '1')
		mycub->plr->posy += mycub->planey * MS;
}

int		keypress(int keycode, t_cub *mycub)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 13 || keycode == 126)
		left(mycub);
	if (keycode == 1 || keycode == 125)
		right(mycub);
	if (keycode == 124)
		rright(mycub);
	if (keycode == 123)
		lleft(mycub);
	if (keycode == 0)
		key123(mycub);
	if (keycode == 2)
		key124(mycub);
	draw_karta(mycub);
	mlx_put_image_to_window(mycub->vs->mx, mycub->vs->wn,
			mycub->img->img, 0, 0);
	return (0);
}
