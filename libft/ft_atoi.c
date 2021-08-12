/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:44:09 by mflor             #+#    #+#             */
/*   Updated: 2020/11/07 16:05:37 by mflor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int			k;
	int			minus;
	int			res[20];
	int			i;
	long long	iscint;

	k = 0;
	while (str[k] == ' ' || str[k] == '\t' || str[k] == '\n'
			|| str[k] == '\r' || str[k] == '\v' || str[k] == '\f')
		k++;
	minus = (str[k] == '-') ? (-1) : 1;
	if (str[k] == '-' || str[k] == '+')
		k++;
	i = 0;
	iscint = 0;
	while (57 >= str[k] && str[k] >= 48)
	{
		res[i] = str[k] - '0';
		if ((iscint * 10) < iscint)
			return (minus == -1 ? 0 : (-1));
		iscint = (iscint * 10) + res[i];
		i++;
		k++;
	}
	return (iscint * minus);
}
