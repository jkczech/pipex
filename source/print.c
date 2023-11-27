/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:53:25 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/27 13:35:05 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	print_array(char *name, char **array)
{
	int	i;

	i = 0;
	ft_printf("%s: ");
	while (array[i])
	{
		ft_printf("\"%s\" ", array[i]);
		i++;
	}
	ft_printf("\n");
	return ;
}

void	print_pipex(t_pipex pipex)
{
	ft_printf("The Path is: %s\n", pipex.path);
	ft_printf("infile: %d\n", pipex.infile);
	ft_printf("outfile: %d\n", pipex.outfile);
	ft_printf("pipe1: %d\n", pipex.mypipe[0]);
	ft_printf("pipe2: %d\n", pipex.mypipe[1]);
	print_array("Command 1", pipex.commands[0]);
	print_array("Command 2", pipex.commands[1]);
}
