/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:04:36 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/15 15:29:37 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* if (precision == 0)
		{
			
			res[*slen] = ((int)round(n)) % 10 + '0';

			while (((int)round(n) % 10 != (int)(float)n % 10
					&& res[(*slen) + 1] == '\0')
				|| (res[*slen] == '0' && res[(*slen) + 1] != '\0'))
			{
				if (*slen == 0)
				{
					printf("here\n");
					res = ft_strjoin("0", res);
					(*slen)++;
					printf("res: %s\n", res);
				}
				if (res[*slen - 1] == '.')
					(*slen)--;
				if (res[*slen - 1] == '9')
					res[*slen - 1] = '0';
				else
					res[*slen - 1]++;
				(*slen)--;
			}

		}
		else */
//no rounding implemented, my try is above
char	*dtoa2(double n, int precision, char *res)
{
	int	slen;

	if (precision == 0)
	{
		free(res);
		return (ft_itoa((int)(float)(n)));
	}
	slen = intlen((int)n);
	if ((int)n == 0 && n < 0)
		(slen)++;
	res[slen] = '.';
	slen++;
	if (n < 0)
		n = -n;
	res[slen + precision] = '\0';
	while (precision-- > 0)
	{
		n *= 10;
		res[slen] = (int)n % 10 + '0';
		slen++;
	}
	return (res);
}

char	*ft_dtoa(double n, int precision)
{
	int				slen;
	char			*res;
	unsigned int	nn;

	slen = intlen((int)n);
	res = malloc((slen + precision + 3) * sizeof(char));
	if (!res)
		return (0);
	res[0] = '0';
	nn = n;
	if (n < 0)
	{
		res[0] = '-';
		res[1] = '0';
		nn = -n;
		if (n == -2147483648)
			nn = 2147483648;
	}
	while (nn > 0)
	{
		res[slen-- - 1] = (nn % 10) + '0';
		nn /= 10;
	}
	return (dtoa2(n, precision, res));
}

/* int	main(int argc, char **argv)
{
	char	*num;
	
	if (argc != 3)
		return (1);
	num = ft_dtoa(atof(argv[1]), atoi(argv[2]));
	printf("%s\n", num);
	free(num);
	return (0);
} */