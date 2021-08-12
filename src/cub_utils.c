/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:38:01 by mflor             #+#    #+#             */
/*   Updated: 2021/03/11 04:04:58 by mflor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../minilibx_mms/main.h"
#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->ll + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int		get_color(t_txt *txt, int x, int y)
{
	char *dst;

	dst = txt->addr + (y * txt->ll + x * (txt->bpp / 8));
	return (*(int *)dst);
}

int		ft_error(int p)
{
	if (p == -1)
		write(1, "Error\nMalloc problem\n", 21);
	if (p == -2)
		write(1, "Error\nMap is open from west side!\n", 34);
	if (p == -3)
		write(1, "Error\nV karte lishnie elementy!\n", 32);
	if (p == -4)
		write(1, "Error\nV karte lishnie igroki!\n", 30);
	if (p == -5)
		write(1, "Error\nV karte pustaya stroka!\n", 30);
	if (p == -7)
		write(1, "Error\nChto-to s argumentami ne tak!\n", 36);
	if (p == -8)
		write(1, "Error\nWrong resolution!\n", 25);
	if (p == -9)
		write(1, "Error\nWrong color of ceil or floor!\n", 37);
	if (p == -10)
		write(1, "Error\nWrong xpm file!\n", 21);
	if (p == -11)
		write(1, "Error\nCouldn't get address of file!\n", 42);
	if (p == -12)
		write(1, "Error\nCan't open map!\n", 21);
	if (p == -13)
		write(1, "Error\nWrong texture!\n", 20);
	exit(0);
}

int		surround(char c, char *s)
{
	int i;

	i = -1;
	if (c == '\0')
		return (0);
	while (s[++i] != '\0')
		if (s[i] == c)
			return (1);
	return (0);
}

int		check_zero(char **wmap, int a, int b)
{
	if (a - 1 >= 0)
		if (surround(wmap[a - 1][b - 1], CH))
			if (surround(wmap[a - 1][b], CH))
				if (surround(wmap[a - 1][b + 1], CH))
					if (surround(wmap[a][b - 1], CH))
						if (surround(wmap[a][b + 1], CH))
							if (wmap[a + 1])
								if (surround(wmap[a + 1][b - 1], CH))
									if (surround(wmap[a + 1][b], CH))
										if (surround(wmap[a + 1][b + 1], CH))
											return (1);
	write(1, "Error\nKarta ne zakryta! (2 or P)\n", 33);
	return (0);
}
