/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:50:23 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/15 15:29:51 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	intlen(int n)
{
	size_t	len;

	len = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		slen;
	char	*res;
	size_t	nn;

	slen = intlen(n);
	res = malloc((slen + 1) * sizeof(char));
	if (!res)
		return (0);
	res[slen] = '\0';
	res[0] = '0';
	nn = n;
	if (n < 0)
	{
		res[0] = '-';
		nn = -n;
		if (n == -2147483648)
			nn = 2147483648;
	}
	while (nn > 0)
	{
		res[slen - 1] = (nn % 10) + '0';
		nn /= 10;
		slen--;
	}
	return (res);
}
