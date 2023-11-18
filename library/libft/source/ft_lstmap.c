/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:56:53 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/15 15:30:16 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*head;

	if (!lst || !f || !del)
		return (0);
	head = NULL;
	while (lst)
	{
		node = ft_lstnew((*f)(lst->content));
		if (!node)
		{
			ft_lstclear(&lst, del);
			return (0);
		}
		ft_lstadd_back(&head, node);
		lst = lst->next;
	}
	return (head);
}
