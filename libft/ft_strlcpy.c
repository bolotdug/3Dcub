/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:37:35 by mflor             #+#    #+#             */
/*   Updated: 2020/11/08 03:53:08 by mflor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	tmp;
	char	*src2;

	if (src == 0)
		return (0);
	src2 = (char*)src;
	tmp = 0;
	if (dstsize == 0)
		return (ft_strlen(src2));
	while (tmp < dstsize - 1 && src2[tmp])
	{
		dst[tmp] = src2[tmp];
		tmp++;
	}
	dst[tmp] = '\0';
	return (ft_strlen(src2));
}
