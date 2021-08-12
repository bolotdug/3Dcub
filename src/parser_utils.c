/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:29:58 by mflor             #+#    #+#             */
/*   Updated: 2021/03/11 04:06:21 by mflor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int		wmapmalloc(char **map)
{
	int a;
	int b;
	int c;
	int flag;

	flag = 1;
	a = -1;
	while (map[++a])
	{
		b = 0;
		while (map[a][b] == ' ')
			b++;
		if (map[a][b] == '1' && flag)
		{
			c = a;
			flag = 0;
		}
		while (map[a][b] != '\0')
			b++;
	}
	return (a - c);
}

void	copymap(t_cub *mycub, char **map, int count, int a)
{
	int c;

	if (count != 726)
		ft_error(-7);
	c = 0;
	while (map[a])
		mycub->worldmap[c++] = map[a++];
	mycub->worldmap[c] = NULL;
}

int		resolution(t_cub *mycub, char *map, int b)
{
	int c[2];

	c[0] = ft_atoi(map + b);
	mycub->carg += 'R';
	mycub->karta.x = c[0] > mycub->karta.x ? mycub->karta.x : c[0];
	if (mycub->karta.x < 0)
		ft_error(-8);
	while (map[b] == ' ')
		b++;
	while ('0' <= map[b] && map[b] <= '9')
		b++;
	c[1] = ft_atoi(map + b);
	mycub->karta.y = c[1] > mycub->karta.y ? mycub->karta.y : c[1];
	if (mycub->karta.y < 0)
		ft_error(-8);
	while (map[b] == ' ')
		b++;
	while ('0' <= map[b] && map[b] <= '9')
		b++;
	if (map[b] != '\0')
		ft_error(-8);
	return (1);
}

int		check_color(t_col *c)
{
	if (0 <= c->r && c->r <= 255)
		if (0 <= c->g && c->g <= 255)
			if (0 <= c->b && c->b <= 255)
				return (1);
	ft_error(-9);
	return (0);
}
