/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 08:58:50 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/15 15:30:29 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*ddest;
	const char	*ssrc;

	if (dest == NULL || src == NULL)
		return (0);
	ddest = (char *)dest;
	ssrc = (const char *)src;
	i = 0;
	while (i < n)
	{
		ddest[i] = ssrc[i];
		i++;
	}
	return (dest);
}
