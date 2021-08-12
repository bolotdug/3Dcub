/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 16:42:48 by mflor             #+#    #+#             */
/*   Updated: 2020/12/17 15:09:40 by mflor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr1(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
		{
			return ((char*)s);
		}
		s++;
	}
	if (*s == (unsigned char)c)
	{
		return ((char*)s);
	}
	return (NULL);
}

size_t	ft_strlen1(const char *str, char c)
{
	int k;

	if (str == NULL)
		return (0);
	k = 0;
	while (str[k] != c && str[k])
		k++;
	return (k);
}

char	*ft_strjoin1(char const *s1, char const *s2)
{
	char	*ret;
	int		l1;
	int		l2;

	if (s1 == 0)
	{
		ret = ft_strdup(s2);
		return (ret);
	}
	l1 = ft_strlen1((char*)s1, '\0');
	l2 = ft_strlen1((char*)s2, '\0');
	ret = malloc(l1 + l2 + 1);
	if (ret == NULL)
		return (NULL);
	l1 = 0;
	l2 = 0;
	while (s1[l2] != '\0')
		ret[l1++] = s1[l2++];
	l2 = 0;
	while (s2[l2] != '\0')
		ret[l1++] = s2[l2++];
	ret[l1] = '\0';
	return (ret);
}

char	*ft_strdup1(const char *s1)
{
	char	*dest;
	int		t;

	dest = (char*)malloc(ft_strlen1((char*)s1, '\0') + 1);
	if (dest == NULL)
		return (NULL);
	t = 0;
	while (s1[t] != '\0')
	{
		dest[t] = s1[t];
		t++;
	}
	dest[t] = '\0';
	return (dest);
}
