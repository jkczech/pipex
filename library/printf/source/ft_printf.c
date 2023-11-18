/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:44:22 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/17 19:03:41 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_simple_va(va_list args, char spec)
{
	int	printlen;

	printlen = 0;
	if (spec == 'c')
		printlen += ft_putchar_fd(va_arg(args, int), 1);
	else if (spec == 'i' || spec == 'd')
		printlen += ft_putnbr_fd(va_arg(args, int), 1);
	else if (spec == 's')
		printlen += ft_putstr_fd(va_arg(args, char *), 1);
	else if (spec == 'p')
		printlen += ft_putptr_fd(va_arg(args, unsigned long long), 1);
	else if (spec == 'u')
		printlen += ft_putnbr_fd(va_arg(args, unsigned int), 1);
	else if (spec == 'x' || spec == 'X')
		printlen += ft_puthexa(va_arg(args, int), spec);
	else if (spec == '%')
		printlen += ft_putchar_fd('%', 1);
	return (printlen);
}

int	read_va(const char *format, int *i, va_list args)
{
	int	printlen;

	printlen = 0;
	if (is_correct_flag(format, i))
		printlen += print_flag_va(format, i, args);
	else if (is_skip_flag(format, i))
	{
		printlen += print_simple_va(args, format[*i + 2]);
		(*i)++;
	}
	else
		printlen += print_simple_va(args, format[*i + 1]);
	if (isspec(format[*i + 1]))
		(*i)++;
	return (printlen);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	vars;
	int		printlen;

	i = 0;
	printlen = 0;
	if (!format || format[0] == '\0')
		return (-1);
	va_start(vars, format);
	while (format[i])
	{
		if (format[i] == '%')
			printlen += read_va(format, &i, vars);
		else
			printlen += write(1, &format[i], 1);
		i++;
	}
	va_end(vars);
	return (printlen);
}

/* #include <stdio.h>

int	main(void)
{

	char c = 'C';
	char *str = "string";
	void *ptr = &str;
	int d = -123456;
	int i = +123456;
	unsigned int	u = 123456;
	int x = 0xfa12;
	int X = 0xfa12;

	int	res;

	res = 0;
	printf("----------------------------------------------\n");
	printf("Basic Tests:\n");
	printf("ft_printf:\n");
	res = ft_printf("\t%c, %s, %p, %d, %i, %u, %x, %X, %%\n",
			c, str, ptr, d, i, u, x, X);
	printf("\tReturn value: %d\n", res);
	printf("printf:\n");
	res = printf("\t%c, %s, %p, %d, %i, %u, %x, %X, %%\n",
			c, str, ptr, d, i, u, x, X);
	printf("\tReturn value: %d\n", res);
	printf("----------------------------------------------\n");

	c = NULL;
	str = NULL;
	ptr = NULL;
	d = NULL;
	i = NULL;
	u = NULL;
	x = NULL;
	X = NULL;

	printf("NULL Tests:\n");
	printf("ft_printf:\n");
	res = ft_printf("\t%c, %s, %p, %d, %i, %u, %x, %X, %%\n",
			c, str, ptr, d, i, u, x, X);
	printf("\tReturn value: %d\n", res);
	printf("printf:\n");
	res = printf("\t%c, %s, %p, %d, %i, %u, %x, %X, %%\n",
			c, str, ptr, d, i, u, x, X);
	printf("\tReturn value: %d\n", res);
	printf("----------------------------------------------\n");

	c = NULL;
	str = NULL;
	ptr = NULL;
	d = NULL;
	i = NULL;
	u = NULL;
	x = NULL;
	X = NULL;

	printf("Space (' ') Tests:\n");
	printf("ft_printf:\n");
	res = ft_printf("\t% c, % s, % p, % d, % i, % u, % x, % X, % %\n",
			c, str, ptr, d, i, u, x, X);
	printf("\tReturn value: %d\n", res);
	printf("printf:\n");
	res = printf("\t% c, % s, % p, % d, % i, % u, % x, % X, % %\n",
			c, str, ptr, d, i, u, x, X);
	printf("\tReturn value: %d\n", res);
	printf("----------------------------------------------\n");

	c = NULL;
	str = NULL;
	ptr = NULL;
	d = NULL;
	i = NULL;
	u = NULL;
	x = NULL;
	X = NULL;

	printf("Plus (+) Tests:\n");
	printf("ft_printf:\n");
	res = ft_printf("\t%+c, %+s, %+p, %+d, %+i, %+u, %+x, %+X, %+%\n",
			c, str, ptr, d, i, u, x, X);
	printf("\tReturn value: %d\n", res);
	printf("printf:\n");
	res = printf("\t%+c, %+s, %+p, %+d, %+i, %+u, %+x, %+X, %+%\n",
			c, str, ptr, d, i, u, x, X);
	printf("\tReturn value: %d\n", res);
	printf("----------------------------------------------\n");

	c = NULL;
	str = NULL;
	ptr = NULL;
	d = NULL;
	i = NULL;
	u = NULL;
	x = 1;
	X = 1;

	printf("Sharp (#) Tests:\n");
	printf("ft_printf:\n");
	res = ft_printf("\t%#c, %#s, %#p, %#d, %#i, %#u, %#x, %#X, %#%\n",
			c, str, ptr, d, i, u, x, X);
	printf ("\tReturn value: %d\n", res);
	printf("printf:\n");
	res = printf("\t%#c, %#s, %#p, %#d, %#i, %#u, %#x, %#X, %#%\n",
			c, str, ptr, d, i, u, x, X);
	printf ("\tReturn value: %d\n", res);
	printf("----------------------------------------------\n");

	printf("Custom Test:\n");
	printf("ft_printf:\n");
	res = ft_printf("\t%c%s%d%i%u%x%X%% %c%s%d%i%u%x%X%% %c%s%d%i%u%x%X%% %c\n",
			'A', "42", 42, 42, 42, 42, 42, 'B', "-42", -42, -42, -42,
			-42, 42, 'C', "0", 0, 0, 0, 0, 42, 0);
	printf ("\tReturn value: %d\n", res);
	printf("printf:\n");
	res = printf("\t%c%s%d%i%u%x%X%% %c%s%d%i%u%x%X%% %c%s%d%i%u%x%X%% %c\n",
			'A', "42", 42, 42, 42, 42, 42, 'B', "-42", -42, -42, -42,
			-42, 42, 'C', "0", 0, 0, 0, 0, 42, 0);
	printf ("\tReturn value: %d\n", res);
	printf("----------------------------------------------\n");
	return (0);
}
 */
