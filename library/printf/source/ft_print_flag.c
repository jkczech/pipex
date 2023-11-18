/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:19:55 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/17 19:03:37 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_plus_space(const char *format, int *i, int num)
{
	int	printlen;

	printlen = 0;
	if (num >= 0)
		printlen += ft_putchar_fd(format[*i + 1], 1);
	printlen += ft_putnbr_fd(num, 1);
	return (printlen);
}

int	print_sharp(const char *format, int *i, int num)
{
	int	printlen;

	printlen = 0;
	if (num != 0)
	{
		printlen += ft_putchar_fd('0', 1);
		printlen += ft_putchar_fd(format[*i + 2], 1);
	}
	printlen += ft_puthexa(num, format[*i + 2]);
	return (printlen);
}

int	print_space(const char *format, int *i, char *str)
{
	int	printlen;

	printlen = 0;
	if (format[*i + 2] == 's')
		printlen += ft_putstr_fd(str, 1);
	else if (ft_isdigit(format[*i + 2]) && format[*i + 3] == 's')
	{
		printlen += ft_putchar_fd(' ', 1);
		printlen += ft_putstr_fd(str, 1);
		*i += 2;
	}
	return (printlen);
}

int	print_flag_va(const char *format, int *i, va_list args)
{
	int		printlen;
	int		num;
	char	*str;

	printlen = 0;
	if ((format[*i + 2] == 's'
			|| (ft_isdigit(format[*i + 2]) && format[*i + 3] == 's'))
		&& format[*i + 1] == ' ')
	{
		str = va_arg(args, char *);
		printlen += print_space(format, i, str);
	}
	else
	{
		num = va_arg(args, int);
		if ((format[*i + 1] == '+' || format[*i + 1] == ' ')
			&& (format[*i + 2] == 'd' || format[*i + 2] == 'i'))
			printlen += print_plus_space(format, i, num);
		else if (format[*i + 1] == '#'
			&& (format[*i + 2] == 'x' || format[*i + 2] == 'X'))
			printlen += print_sharp(format, i, num);
	}
	(*i)++;
	return (printlen);
}
