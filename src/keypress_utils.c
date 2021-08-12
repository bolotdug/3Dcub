/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:24:29 by mflor             #+#    #+#             */
/*   Updated: 2021/03/11 02:48:28 by mflor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../minilibx_mms/main.h"
#include "../includes/cub3d.h"

void	left(t_cub *mycub)
{
	int a;
	int b;

	b = (int)(mycub->plr->posy + mycub->dir->diry * MS);
	a = (int)(mycub->plr->posx + mycub->dir->dirx * MS);
	if (mycub->worldmap[a][(int)(mycub->plr->posy)] != '1')
		mycub->plr->posx += mycub->dir->dirx * MS;
	if (mycub->worldmap[(int)(mycub->plr->posx)][b] != '1')
		mycub->plr->posy += mycub->dir->diry * MS;
}

void	right(t_cub *mycub)
{
	int a;
	int b;

	a = (int)(mycub->plr->posx - mycub->dir->dirx * MS);
	b = (int)(mycub->plr->posy - mycub->dir->diry * MS);
	if (mycub->worldmap[a][(int)(mycub->plr->posy)] != '1')
		mycub->plr->posx -= mycub->dir->dirx * MS;
	if (mycub->worldmap[(int)(mycub->plr->posx)][b] != '1')
		mycub->plr->posy -= mycub->dir->diry * MS;
}
