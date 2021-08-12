/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sshot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:41:51 by mflor             #+#    #+#             */
/*   Updated: 2021/03/10 19:42:58 by mflor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	int_to_char(int n, unsigned char *src)
{
	src[0] = (unsigned char)(n);
	src[1] = (unsigned char)(n >> 8);
	src[2] = (unsigned char)(n >> 16);
	src[3] = (unsigned char)(n >> 24);
}

static void	bmp_hdr(t_cub *mycub, int file_size, int fd)
{
	unsigned char bmp[54];

	ft_bzero(bmp, 54);
	bmp[0] = (unsigned char)('B');
	bmp[1] = (unsigned char)('M');
	int_to_char(file_size, bmp + 2);
	bmp[10] = (unsigned char)(54);
	bmp[14] = (unsigned char)(40);
	int_to_char(mycub->karta.x, bmp + 18);
	int_to_char(mycub->karta.y, bmp + 22);
	bmp[26] = (unsigned char)(1);
	bmp[28] = (unsigned char)(24);
	write(fd, bmp, 54);
}

static void	get_pxl(t_cub *mycub, int fd)
{
	int	i;
	int	j;
	int	color;

	i = mycub->karta.y - 1;
	while (i >= 0)
	{
		j = -1;
		while (++j < mycub->karta.x)
		{
			color = *(int*)(mycub->img->addr +
							(i * mycub->img->ll + j * (mycub->img->bpp / 8)));
			write(fd, &color, 3);
		}
		i--;
	}
}

int			ft_sshot(t_cub *mycub)
{
	int	fd;
	int	l;

	while (mycub->karta.x % 4 != 0)
		mycub->karta.x--;
	l = 54 + (4 * mycub->karta.y * mycub->karta.x);
	if (!(fd = open("screen.bmp", O_WRONLY |
					O_CREAT | O_TRUNC | O_APPEND, 0666)))
		ft_close(1);
	bmp_hdr(mycub, l, fd);
	get_pxl(mycub, fd);
	close(fd);
	return (1);
}
