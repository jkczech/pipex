/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:11:47 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/15 15:29:39 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t nmemb, size_t sizei)
{
	void	*ptr;
	size_t	size;

	size = nmemb * sizei;
	if (nmemb != 0 && sizei != 0 && size / sizei != nmemb)
		return (0);
	ptr = malloc(size);
	if (ptr)
		ft_bzero(ptr, size);
	return (ptr);
}
