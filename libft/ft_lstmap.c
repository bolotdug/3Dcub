/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:54:41 by mflor             #+#    #+#             */
/*   Updated: 2020/11/09 13:09:53 by mflor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *newel;
	t_list *temp;

	newel = NULL;
	temp = NULL;
	if (lst == NULL)
		return (NULL);
	if (lst && f)
	{
		while (lst)
		{
			temp = ft_lstnew(f(lst->content));
			if (temp == NULL)
			{
				ft_lstclear(&temp, del);
				return (NULL);
			}
			ft_lstadd_back(&newel, temp);
			lst = lst->next;
		}
	}
	return (newel);
}
