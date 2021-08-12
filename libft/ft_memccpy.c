/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 23:58:11 by mflor             #+#    #+#             */
/*   Updated: 2020/11/04 00:28:57 by mflor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst2;
	unsigned char	*src2;
	size_t			k;

	k = 0;
	dst2 = (unsigned char*)dst;
	src2 = (unsigned char*)src;
	while (k < n)
	{
		if (src2[k] == (unsigned char)c)
		{
			dst2[k] = src2[k];
			return (dst2 + k + 1);
		}
		dst2[k] = src2[k];
		k++;
	}
	return (NULL);
}
