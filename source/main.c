/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:26:55 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/23 13:02:39 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		return (1);
	pipex.infile = open(argv[1], O_WRONLY | O_CREAT, 0777);
	if (!pipex.infile)
		return (1);
	pipex.commands[0] = *ft_split(argv[2], ' ');
	pipex.commands[0] = *ft_split(argv[3], ' ');
	pipex.outfile = open(argv[4], O_RDONLY | O_CREAT, 0777);
	if (!pipex.outfile)
		return (1);
	if (pipe(pipex.mypipe) == -1)
		return (1);
	pipex.path = find_path(envp);
	close_files(pipex);
	return (0);
}

char	*find_path(char **envp)
{
	int	i;

	i = 0;
	while (strncmp(envp[i], "PATH", 4) != 0)
		i++;
	return (envp[i]);
}

void	close_files(t_pipex pipex)
{
	close(pipex.infile);
	close(pipex.outfile);
}
