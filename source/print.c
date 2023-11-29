/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:53:25 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/29 14:45:55 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

//prints elements of a string array
void	print_array(char *name, char **array)
{
	int	i;

	i = 0;
	ft_printf("%s: ", name);
	while (array[i])
	{
		ft_printf("\"%s\" ", array[i]);
		i++;
	}
	ft_printf("\n");
	return ;
}

//prints elements of pipex structure
void	print_pipex(t_pipex pipex)
{
	int	i;

	print_array("The Paths are", pipex.paths);
	ft_printf("infile: %d\n", pipex.infile);
	ft_printf("outfile: %d\n", pipex.outfile);
	ft_printf("pipe1: %d\n", pipex.mypipe[0]);
	ft_printf("pipe2: %d\n", pipex.mypipe[1]);
	i = 0;
	while (i < pipex.size)
	{
		print_array("cmd", pipex.cmd[i].args);
		ft_printf("path: %s\n", pipex.cmd[i].path);
		i++;
	}
}
