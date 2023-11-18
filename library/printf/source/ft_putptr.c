/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:36:35 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/17 19:03:46 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putnbr_ptr_fd(unsigned long int nbr, int fd)
{
	unsigned long int	base_num;
	int					printlen;
	char				*base;

	printlen = 0;
	base = "0123456789abcdef";
	base_num = ft_strlen(base);
	if (nbr >= base_num)
	{
		printlen += ft_putnbr_ptr_fd(nbr / base_num, fd);
		nbr %= base_num;
	}
	if (nbr < base_num)
	{
		ft_putchar_fd(base[nbr], fd);
		printlen++;
	}
	return (printlen);
}

int	ft_putptr_fd(unsigned long int ptr, int fd)
{
	int	printlen;

	if (ptr == 0)
		return (ft_putstr_fd("(nil)", fd));
	printlen = 0;
	printlen += ft_putstr_fd("0x", fd);
	printlen += ft_putnbr_ptr_fd(ptr, fd);
	return (printlen);
}
