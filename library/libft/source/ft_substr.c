/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:50:18 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/15 15:31:22 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;
	size_t	slen;
	size_t	sublen;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (start >= slen)
		sublen = 0;
	else if (len + start <= slen)
		sublen = len;
	else
		sublen = slen - start;
	substr = malloc((sublen + 1) * sizeof(char));
	if (!substr)
		return (0);
	i = 0;
	while (i < sublen)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
