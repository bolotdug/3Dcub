/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:24:59 by mflor             #+#    #+#             */
/*   Updated: 2020/11/04 00:03:30 by mflor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t count)
{
	unsigned char	*temp;
	size_t			tc;

	tc = count;
	temp = (unsigned char *)buf;
	while (count--)
	{
		*temp++ = (unsigned char)ch;
	}
	return (temp - tc);
}
