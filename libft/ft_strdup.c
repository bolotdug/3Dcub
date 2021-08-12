/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:44:46 by mflor             #+#    #+#             */
/*   Updated: 2020/11/10 16:01:28 by mflor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy2(const char *src, char *dest)
{
	int t;

	t = 0;
	while (src[t] != '\0')
	{
		dest[t] = src[t];
		t++;
	}
	dest[t] = '\0';
	return (dest);
}

char		*ft_strdup(const char *s1)
{
	char	*dest;

	dest = (char*)malloc(ft_strlen((char*)s1) + 1);
	if (dest == NULL)
		return (NULL);
	dest = ft_strcpy2(s1, dest);
	return (dest);
}
