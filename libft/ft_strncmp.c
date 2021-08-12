/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 00:46:48 by mflor             #+#    #+#             */
/*   Updated: 2020/11/04 00:01:57 by mflor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *st1, const char *st2, size_t n)
{
	size_t			c;
	unsigned char	*s1;
	unsigned char	*s2;

	c = 0;
	s1 = (unsigned char*)st1;
	s2 = (unsigned char*)st2;
	while (c < n && (s1[c] || s2[c]))
	{
		if (s1[c] < s2[c])
			return (-1);
		else if (s1[c] > s2[c])
			return (s1[c] - s2[c]);
		c++;
	}
	return (0);
}
