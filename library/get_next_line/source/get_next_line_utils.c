/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:41:36 by jkoupy            #+#    #+#             */
/*   Updated: 2023/12/17 13:27:58 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

void	free_list(t_list **llist, char *new_content)
{
	t_list	*tmp;

	while (*llist)
	{
		free((*llist)->content);
		tmp = (*llist)->next;
		free(*llist);
		*llist = tmp;
	}
	if (new_content)
		*llist = ft_lstnew(new_content);
}

int	line_length(t_list *llist)
{
	int	i;
	int	len;

	len = 0;
	if (!llist || !llist->content[0])
		return (0);
	while (llist)
	{
		i = 0;
		while (llist->content[i])
		{
			if (llist->content[i] == '\n')
				return (len + i + 1);
			i++;
		}
		len += i;
		llist = llist->next;
	}
	return (len);
}

void	ft_lstadd_new(t_list **lst, char *new_content)
{
	t_list	*temp;
	t_list	*new;

	new = ft_lstnew(new_content);
	if (!*lst && new)
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast(*lst);
	temp->next = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (0);
	list->content = content;
	list->next = NULL;
	return (list);
}
