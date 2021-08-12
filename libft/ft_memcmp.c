/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 01:02:59 by mflor             #+#    #+#             */
/*   Updated: 2020/11/03 23:55:11 by mflor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *st1, const void *st2, size_t n)
{
	size_t			c;
	unsigned char	*s1;
	unsigned char	*s2;

	c = 0;
	s1 = (unsigned char*)st1;
	s2 = (unsigned char*)st2;
	while (c < n)
	{
		if (s1[c] < s2[c])
			return (s1[c] - s2[c]);
		else if (s1[c] > s2[c])
			return (s1[c] - s2[c]);
		c++;
	}
	return (0);
}
