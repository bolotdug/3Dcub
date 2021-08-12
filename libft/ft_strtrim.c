/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:31:20 by mflor             #+#    #+#             */
/*   Updated: 2020/11/07 16:41:53 by mflor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tr;
	int		t;
	int		k;
	int		len;

	if (s1 == 0 || set == 0)
		return (0);
	t = 0;
	while (ft_strchr(set, s1[t]) != NULL)
		t++;
	len = ft_strlen((char*)s1);
	while (ft_strrchr(set, s1[len]) != NULL)
		len--;
	if (len > t)
		tr = malloc(len - t + 2);
	else
		return (ft_strdup(""));
	if (tr == NULL)
		return (NULL);
	k = 0;
	while (t <= len)
		tr[k++] = s1[t++];
	tr[k] = '\0';
	return (tr);
}
