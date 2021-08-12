/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 00:24:11 by mflor             #+#    #+#             */
/*   Updated: 2020/11/07 01:03:27 by mflor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	func(int n, int fd)
{
	long long k;

	k = n;
	if (n < 0)
	{
		k = -k;
		ft_putchar_fd('-', fd);
	}
	if (k > 0)
	{
		func(k / 10, fd);
		ft_putchar_fd((k % 10) + '0', fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		ft_putchar_fd('0', fd);
	else
		func(n, fd);
}
