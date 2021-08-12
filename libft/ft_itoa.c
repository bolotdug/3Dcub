/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 22:56:13 by mflor             #+#    #+#             */
/*   Updated: 2020/11/07 23:29:39 by mflor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	dlina(int n)
{
	long long	k;
	int			res;

	res = 0;
	k = n;
	if (n < 0)
	{
		k = -k;
		res++;
	}
	while (k > 0)
	{
		k = k / 10;
		res++;
	}
	return (res);
}

static char	*func(char *ret, int n, int len)
{
	long long	k;

	k = n;
	if (n < 0)
	{
		k = -k;
		ret[0] = '-';
	}
	n = len;
	while (k > 0)
	{
		ret[len] = (k % 10) + '0';
		k = k / 10;
		len--;
	}
	ret[n + 1] = '\0';
	return (ret);
}

char		*ft_itoa(int n)
{
	char	*ret;
	int		len;
	int		k;
	int		t;

	if (n == 0)
	{
		ret = (char*)malloc(2);
		ret[0] = '0';
		ret[1] = '\0';
		return (ret);
	}
	k = n;
	t = 1;
	len = dlina(n);
	ret = (char*)malloc(len + 1);
	if (ret == NULL)
		return (NULL);
	ret = func(ret, n, len - 1);
	return (ret);
}
