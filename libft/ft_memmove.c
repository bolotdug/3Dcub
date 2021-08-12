/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 01:00:49 by mflor             #+#    #+#             */
/*   Updated: 2020/11/04 04:33:54 by mflor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst2;
	unsigned char	*src2;

	if (src == ((void*)0) && dst == ((void*)0))
		return (dst);
	dst2 = (unsigned char*)dst;
	src2 = (unsigned char*)src;
	if (src < dst)
	{
		while (len-- != 0)
			dst2[len] = src2[len];
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
