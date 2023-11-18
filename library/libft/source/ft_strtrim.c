/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:14:20 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/15 15:31:20 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	isinset(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	first;
	size_t	last;

	if (!s1)
		return (0);
	first = 0;
	while (s1[first] && isinset(s1[first], set))
		first++;
	if (!s1[first])
	{
		res = malloc(1);
		res[0] = '\0';
		return (res);
	}
	last = ft_strlen(s1) - 1;
	while (s1[last] && isinset(s1[last], set))
		last--;
	res = malloc((last - first + 2) * sizeof(char));
	if (!res)
		return (0);
	ft_strncpy(res, &s1[first], (last - first + 1));
	res[last - first + 1] = '\0';
	return (res);
}
