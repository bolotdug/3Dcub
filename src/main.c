/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflor <mflor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:55:03 by mflor             #+#    #+#             */
/*   Updated: 2021/03/11 04:57:05 by mflor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	workmxl(t_cub *mc, int sshot)
{
	mc->vs->wn = mlx_new_window(mc->vs->mx, mc->karta.x, mc->karta.y, "cub3D");
	if (!(mc->img->img = mlx_new_image(mc->vs->mx, mc->karta.x, mc->karta.y)))
		ft_close(2);
	mc->img->addr = mlx_get_data_addr(mc->img->img, &mc->img->bpp,
			&mc->img->ll, &mc->img->end);
	draw_karta(mc);
	mlx_put_image_to_window(mc->vs->mx, mc->vs->wn, mc->img->img, 0, 0);
	if (sshot == 1)
	{
		ft_sshot(mc);
		exit(0);
	}
	mlx_hook(mc->vs->wn, 2, 1L << 0, keypress, mc);
	mlx_hook(mc->vs->wn, 17, 1L << 2, ft_close, mc);
	mlx_loop(mc->vs->mx);
}

void	initst(char **map, int sshot, t_cub *mc)
{
	t_txt	not;
	t_txt	eat;
	t_txt	wet;
	t_txt	sot;
	t_txt	st;

	mc->not = &not;
	mc->sot = &sot;
	mc->eat = &eat;
	mc->wet = &wet;
	mc->st = &st;
	if (!(mc->vs->mx = mlx_init()))
		ft_close(3);
	mlx_get_screen_size(mc->vs->mx, &mc->karta.x, &mc->karta.y);
	if (parser(map, mc))
		workmxl(mc, sshot);
}

void	workwithmxl(char **map, int sshot)
{
	t_cub	mc;
	t_plr	plr;
	t_dir	dir;
	t_data	img;
	t_vs	vs;

	mc.img = &img;
	mc.vs = &vs;
	mc.plr = &plr;
	mc.dir = &dir;
	initst(map, sshot, &mc);
}

int		ft_obrab(char *karta, int sshot)
{
	int		fd;
	char	*line;
	char	**map;
	int		a;
	int		c;

	a = 0;
	c = hmmaloc(karta);
	if ((fd = open(karta, O_RDONLY)) < 0)
		ft_error(-12);
	if (!(map = (char **)malloc(sizeof(char*) * c + 1)))
		ft_error(-1);
	while (get_next_line(fd, &line) > 0)
		map[a++] = line;
	map[a] = line;
	map[++a] = NULL;
	close(fd);
	workwithmxl(map, sshot);
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc == 2 && checkname(argv[1]))
		ft_obrab(argv[1], 0);
	else if (argc == 3 && checkname2(argv[2], argv[1]))
		ft_obrab(argv[1], 1);
	else
		printf("Error\nChto-to posholo ne tak!\n");
	return (0);
}
