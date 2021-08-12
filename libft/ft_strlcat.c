/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 22:36:13 by mflor             #+#    #+#             */
/*   Updated: 2020/11/04 19:13:44 by mflor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	tmp;
	char	*src2;
	size_t	tmp2;

	src2 = (char*)src;
	tmp = 0;
	tmp2 = 0;
	while (dst[tmp] != '\0' && tmp < dstsize)
		tmp++;
	if (dstsize == tmp)
		return (dstsize + ft_strlen(src2));
	tmp2 = tmp;
	while (tmp2 < dstsize - 1 && src2[tmp2 - tmp] != '\0')
	{
		dst[tmp2] = src2[tmp2 - tmp];
		tmp2++;
	}
	dst[tmp2] = '\0';
	return (tmp + ft_strlen(src2));
}
