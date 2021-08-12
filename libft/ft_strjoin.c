/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:11:41 by mflor             #+#    #+#             */
/*   Updated: 2020/11/07 16:40:42 by mflor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		l1;
	int		l2;

	if (s1 == 0 || s2 == 0)
		return (0);
	l1 = ft_strlen((char*)s1);
	l2 = ft_strlen((char*)s2);
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
