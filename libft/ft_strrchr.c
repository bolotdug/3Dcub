/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:47:41 by mflor             #+#    #+#             */
/*   Updated: 2020/11/02 17:37:04 by mflor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		t;
	char	*b;

	b = (char*)s;
	t = ft_strlen((char*)s);
	if (b[t] == (unsigned char)c)
		return (&b[t]);
	while (t--)
	{
		if (b[t] == (unsigned char)c)
			return (&b[t]);
	}
	return (NULL);
}
