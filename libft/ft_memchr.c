/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 00:59:51 by mflor             #+#    #+#             */
/*   Updated: 2020/11/08 00:35:22 by mflor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s2;
	size_t			k;

	s2 = (unsigned char*)s;
	k = 0;
	while (k < n)
	{
		if (s2[k] == (unsigned char)c)
			return ((void*)s2 + k);
		k++;
	}
	return (NULL);
}
