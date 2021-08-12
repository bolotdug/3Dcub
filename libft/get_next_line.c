/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:36:25 by mflor             #+#    #+#             */
/*   Updated: 2020/12/17 15:09:00 by mflor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
# define BUFFER_SIZE  1

static int	konec(char **ost, char **line)
{
	if (ft_strchr1(*ost, '\0'))
	{
		*line = ft_strdup1(*ost);
		free(*ost);
		*ost = NULL;
	}
	return (0);
}

static int	proverka(ssize_t i, char **ost)
{
	if (i < 0)
	{
		if (*ost)
		{
			free(*ost);
			*ost = NULL;
		}
		return (-1);
	}
	return (0);
}

static int	res(char **line, char **ost, ssize_t i)
{
	char *tmp;
	char *tmp2;

	if (proverka(i, &*ost))
		return (-1);
	if (!i && !*ost)
	{
		*line = ft_strdup1("");
		return (0);
	}
	if ((tmp2 = ft_strchr1(*ost, '\n')))
	{
		*tmp2++ = '\0';
		*line = ft_strdup1(*ost);
		tmp = ft_strdup1(tmp2);
		if (!tmp || !*line)
			return (-1);
		free(*ost);
		*ost = tmp;
		return (1);
	}
	return (konec(&*ost, &*line));
}

int			get_next_line(int fd, char **line)
{
	char		*buf;
	ssize_t		i;
	char		*tmp;
	static char *ost[1024];

	tmp = NULL;
	i = 0;
	if (!line || fd < 0 || fd > 1024 || read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
		return (-1);
	if (!(buf = malloc(BUFFER_SIZE + 1)))
		return (-1);
	while ((i = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[i] = '\0';
		tmp = ft_strjoin1(ost[fd], buf);
		free(ost[fd]);
		ost[fd] = tmp;
		if (ft_strchr1(buf, '\n'))
			break ;
		if (i == 0 && !ft_strchr1(ost[fd], '\n'))
			break ;
	}
	free(buf);
	buf = NULL;
	return (res(line, &ost[fd], i));
}
