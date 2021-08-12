/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:46:35 by mflor             #+#    #+#             */
/*   Updated: 2021/03/11 02:38:57 by mflor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_flceil(t_col *c, char *map, int b, t_cub *mycub)
{
	mycub->carg += map[b];
	b++;
	while (map[b] == ' ')
		b++;
	c->r = (ft_isdigit(map[b])) ? ft_atoi(map + b) : ft_error(-9);
	while ('0' <= map[b] && map[b] <= '9')
		b++;
	while (map[b] == ' ')
		b++;
	if (map[b] == ',')
		b++;
	while (map[b] == ' ')
		b++;
	c->g = (ft_isdigit(map[b])) ? ft_atoi(map + b) : ft_error(-9);
	while ('0' <= map[b] && map[b] <= '9')
		b++;
	while (map[b] == ' ')
		b++;
	if (map[b] == ',')
		b++;
	while (map[b] == ' ')
		b++;
	c->b = (ft_isdigit(map[b])) ? ft_atoi(map + b) : ft_error(-9);
	if (check_color(c))
		c->cur = create_rgb(c->r, c->g, c->b);
}

char	*steny(t_cub *mycub, char *map, int b)
{
	mycub->carg += map[--b];
	if (map[b + 2] != ' ')
		ft_error(-13);
	b = b + 2;
	while (map[b] == ' ')
		b++;
	return (map + b);
}

char	*sprite1(t_cub *mycub, char *map, int b)
{
	mycub->carg += 's';
	if (map[b + 1] != ' ')
		ft_error(-13);
	b = b + 1;
	while (map[b] == ' ')
		b++;
	return (map + b);
}

void	arguments(t_cub *mycub, char **map, int a, int b)
{
	if (!(surround(map[a][b], "RSNEWCF1")) && map[a][b])
		ft_error(-7);
	if (map[a][b] == 'R')
		resolution(mycub, map[a], ++b);
	if (map[a][b] == 'E' && map[a][++b] == 'A')
		mycub->ea = steny(mycub, map[a], b);
	if (map[a][b] == 'N' && map[a][++b] == 'O')
		mycub->no = steny(mycub, map[a], b);
	if (map[a][b] == 'W' && map[a][++b] == 'E')
		mycub->we = steny(mycub, map[a], b);
	if (map[a][b] == 'S' && map[a][b + 1] != 'O')
		mycub->s = sprite1(mycub, map[a], b);
	if (map[a][b] == 'S' && map[a][++b] == 'O')
		mycub->so = steny(mycub, map[a], b);
	if (map[a][b] == 'F')
		ft_flceil(&mycub->f, map[a], b, mycub);
	if (map[a][b] == 'C')
		ft_flceil(&mycub->c, map[a], b, mycub);
}

int		parser(char **map, t_cub *mycub)
{
	int a;
	int b;
	int d;

	d = wmapmalloc(map);
	mycub->carg = 0;
	a = -1;
	if (!(mycub->worldmap = (char **)malloc(sizeof(char*) * (d + 1))))
		ft_error(-1);
	while (map[++a])
	{
		b = 0;
		while (map[a][b] == ' ')
			b++;
		if (map[a][b] == '1')
		{
			mycub->carg += 'K';
			copymap(mycub, map, mycub->carg, a);
			break ;
		}
		arguments(mycub, map, a, b);
	}
	txts(mycub);
	return (1);
}
