/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:04:42 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/17 19:03:44 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_puthexa(int nbr, char spec)
{
	int	printlen;

	printlen = 0;
	if (spec == 'x')
		printlen += ft_putnbr_base(nbr, "0123456789abcdef");
	else if (spec == 'X')
		printlen += ft_putnbr_base(nbr, "0123456789ABCDEF");
	return (printlen);
}

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	unsigned int	base_num;
	int				printlen;

	printlen = 0;
	base_num = ft_strlen(base);
	if (nbr >= base_num)
	{
		printlen += ft_putnbr_base(nbr / base_num, base);
		nbr %= base_num;
	}
	if (nbr < base_num)
	{
		ft_putchar_fd(base[nbr], 1);
		printlen++;
	}
	return (printlen);
}
