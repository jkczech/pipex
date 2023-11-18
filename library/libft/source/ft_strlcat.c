/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:18:22 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/15 15:31:04 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;
	size_t	j;

	if (size == 0 && dst == 0)
		return (0);
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	i = 0;
	j = dlen;
	while (1 + j < size && src[i])
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	if (j < size)
		return (dlen + slen);
	return (size + slen);
}
