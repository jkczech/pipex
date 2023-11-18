/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:22:01 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/15 15:31:16 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)big;
	i = 0;
	if (little[0] == '\0')
		return (str);
	if (len == 0)
		return (0);
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] && little[j] && str[i + j] == little[j]
			&& i + j < len)
			j++;
		if (!little[j])
			return (&str[i]);
		i++;
	}
	return (0);
}
