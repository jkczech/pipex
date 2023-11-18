/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:04:17 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/15 15:30:20 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*temp;

	temp = lst;
	size = 0;
	while (temp)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}
