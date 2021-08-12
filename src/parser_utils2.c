/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:30:37 by mflor             #+#    #+#             */
/*   Updated: 2021/03/11 02:41:41 by mflor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	checkplr(char **wm)
{
	int a;
	int b;
	int count;

	a = -1;
	count = 0;
	while (wm[++a])
	{
		b = 0;
		if (!(ft_strncmp(wm[a], "", 2)))
			ft_error(-5);
		while (wm[a][b] != '\0')
		{
			if (wm[a][b] == 'S' || wm[a][b] == 'N'
				|| wm[a][b] == 'E' || wm[a][b] == 'W')
				count++;
			b++;
		}
	}
	if (count > 1)
		ft_error(-4);
}

int		validate(char **wm)
{
	int a;
	int b;

	a = -1;
	while (wm[++a])
	{
		b = 0;
		while (wm[a][b] == ' ')
			b++;
		if (wm[a][b] != '1' && wm[a][b])
			ft_error(-2);
		while (wm[a][b] != '\0')
		{
			if (wm[a][b] == '0' || wm[a][b] == '2' || wm[a][b] == 'S' ||
				wm[a][b] == 'N' || wm[a][b] == 'E' || wm[a][b] == 'W')
			{
				check_zero(wm, a, b);
			}
			else if (!(wm[a][b] == '1' || wm[a][b] == ' '))
				ft_error(-3);
			b++;
		}
	}
	checkplr(wm);
	return (1);
}

void	posplr(t_cub *mycub, int a, int b)
{
	mycub->dir->diry = 0;
	mycub->dir->dirx = 0;
	if (mycub->worldmap[a][b] == 'E')
		mycub->dir->diry = -1;
	else if (mycub->worldmap[a][b] == 'W')
		mycub->dir->diry = 1;
	else if (mycub->worldmap[a][b] == 'S')
		mycub->dir->dirx = 1;
	else if (mycub->worldmap[a][b] == 'N')
		mycub->dir->dirx = -1;
	mycub->plr->posx = a + 0.5;
	mycub->plr->posy = b + 0.5;
	mycub->planex = 0.6 * mycub->dir->diry;
	mycub->planey = -0.6 * mycub->dir->dirx;
}

void	checkplrspr(t_cub *mycub)
{
	int a;
	int b;
	int i;

	i = 0;
	a = -1;
	while (mycub->worldmap[++a])
	{
		b = -1;
		while (mycub->worldmap[a][++b] != '\0')
		{
			if (mycub->worldmap[a][b] == 'E' || mycub->worldmap[a][b] == 'S'
				|| mycub->worldmap[a][b] == 'N'
				|| mycub->worldmap[a][b] == 'W')
				posplr(mycub, a, b);
			if (mycub->worldmap[a][b] == '2')
			{
				mycub->sprite[i].x = a + 0.5;
				mycub->sprite[i++].y = b + 0.5;
			}
		}
	}
}

int		checkmap(t_cub *mycub)
{
	countsprites(mycub);
	mycub->sprite = malloc(sizeof(t_sprite)
			* mycub->numsprites + sizeof(t_sprite));
	if (mycub->sprite == NULL)
		ft_error(-1);
	if (!(validate(mycub->worldmap)))
		return (0);
	checkplrspr(mycub);
	return (1);
}
