/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:35:14 by mflor             #+#    #+#             */
/*   Updated: 2021/03/10 19:11:46 by mflor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../minilibx_mms/main.h"
#include "../includes/cub3d.h"

int		ft_close(int p)
{
	if (p == 4)
		printf("Error\nFailed to check map!\n");
	if (p == 3)
		printf("Error\nFailed to initalize!\n");
	if (p == 2)
		printf("Error\nFailed to get an image!\n");
	if (p == 1)
		printf("Error\nFailed to screenshot!\n");
	if (p < 0)
		printf("Poka chto-li!\n");
	exit(0);
	return (0);
}

int		checkname(char *nazv)
{
	int len;

	len = ft_strlen(nazv);
	if (nazv[--len] == 'b')
		if (nazv[--len] == 'u')
			if (nazv[--len] == 'c')
				if (nazv[--len] == '.')
					return (1);
	return (0);
}

int		checkname2(char *nazv, char *name)
{
	if (ft_strncmp(nazv, "--save", 7) == 0)
		if (checkname(name))
			return (1);
	write(1, "Error\nWrong second argument\n", 28);
	return (0);
}

int		hmmaloc(char *karta)
{
	int		a;
	int		fd;
	char	*line;

	if ((fd = open(karta, O_RDONLY)) < 0)
		ft_error(-12);
	a = 0;
	while (get_next_line(fd, &line) > 0)
	{
		a++;
		free(line);
	}
	free(line);
	close(fd);
	return (a + 1);
}
