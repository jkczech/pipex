/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:26:55 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/27 14:00:47 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		return (1);
	pipex.size = 2;
	if (!load_input(&pipex, argv))
		return (free_pipex(&pipex));
	if (pipe(pipex.mypipe) == -1)
		return (1);
	pipex.path = find_path(envp);
	free_pipex(&pipex);
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

bool	free_pipex(t_pipex *pipex)
{
	close(pipex->infile);
	close(pipex->outfile);
	return (true);
}

bool	load_input(t_pipex *pipex, char **argv)
{
	pipex->infile = open(argv[1], O_WRONLY | O_CREAT, 0777);
	if (!pipex->infile)
		return (false);
	pipex->cmd[0]->args = ft_split(argv[2], ' ');
	pipex->cmd[0].args = ft_split(argv[2], ' ');
	pipex->cmd[1].args = ft_split(argv[3], ' ');
	if (!pipex->cmd[0] || !pipex->cmd[1])
		return (false);
	if (!find_paths(pipex))
		return (false);
	pipex->outfile = open(argv[4], O_RDONLY | O_CREAT, 0777);
	if (!pipex->outfile)
		return (false);
	return (true);
}
bool	find_paths(t_pipex *pipex)
{
	while (pipex->size > 0)
	{
		pipex->size--;
	}
	return (true);
}
