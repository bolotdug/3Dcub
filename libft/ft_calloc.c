/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:35:25 by mflor             #+#    #+#             */
/*   Updated: 2020/11/04 17:19:54 by mflor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*obj;
	size_t	buf;

	buf = count * size;
	obj = malloc(size * count);
	if (obj == NULL)
		return (NULL);
	if (obj)
		ft_bzero(obj, buf);
	return (obj);
}
