/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:52:20 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/17 18:55:56 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//size_t
# include <stddef.h>
//malloc, free
# include <stdlib.h>
//write
# include <unistd.h>
//variadic funcs
# include <stdarg.h>

# include "../../libft/include/libft.h"

//ft_is.c
int	isspec(char c);
int	isflag(char c);
int	is_correct_flag(const char *format, int *i);
int	is_skip_flag(const char *format, int *i);

//other.c
int	print_flag_va(const char *format, int *i, va_list args);
int	ft_printf(const char *format, ...);
int	ft_puthexa(int nbr, char spec);
int	ft_putnbr_base(unsigned int nbr, char *base);
int	ft_putptr_fd(unsigned long int ptr, int fd);

#endif
