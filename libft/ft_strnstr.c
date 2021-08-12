/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 01:34:47 by mflor             #+#    #+#             */
/*   Updated: 2020/11/09 22:46:05 by mflor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	s1;
	int		s2;
	size_t	tmp;

	if (str2[0] == '\0')
		return ((char*)str1);
	s1 = 0;
	while (str1[s1] && s1 < len)
	{
		s2 = 0;
		while (str1[s1] != str2[s2])
			s1++;
		tmp = s1;
		while (str1[s1] == str2[s2] && str2[s2] && s1 < len)
		{
			s1++;
			s2++;
		}
		if (str2[s2] == '\0')
			return ((char*)(str1 + tmp));
		else
			s1 = s1 - s2 + 1;
	}
	return (NULL);
}
