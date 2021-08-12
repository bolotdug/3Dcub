/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 23:00:57 by mflor             #+#    #+#             */
/*   Updated: 2020/11/04 00:00:21 by mflor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst2;
	unsigned char	*src2;
	size_t			k;

	k = 0;
	dst2 = (unsigned char*)dst;
	src2 = (unsigned char*)src;
	if (src2 == dst2)
		return (dst2);
	while (k < n)
	{
		dst2[k] = src2[k];
		k++;
	}
	return (dst2);
}
