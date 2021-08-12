/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:37:05 by mflor             #+#    #+#             */
/*   Updated: 2020/11/11 16:33:22 by mflor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *tmp1;
	t_list *tmp2;

	if (!lst || !del)
		return ;
	tmp1 = *lst;
	while (tmp1)
	{
		del(tmp1->content);
		tmp2 = tmp1;
		tmp1 = tmp1->next;
		free(tmp2);
	}
	*lst = NULL;
}
