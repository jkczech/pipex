/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:26:55 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/29 16:46:10 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

bool	create_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	pipex->pipes = malloc((pipex->size) * sizeof(int *));
	pipex->pipes[pipex->size] = NULL;
	if (!pipex->pipes)
		return (false);
	while (i < pipex->size)
	{
		pipex->pipes[i] = malloc(2 * sizeof(int));
		if (!pipex->pipes[i])
			return (false);
		if (pipe(pipex->pipes[i]) == -1)
			return (false);
	}
}

bool	piping(t_pipex pipex)
{
	int	pid;
	int	i;

	create_pipes(&pipex);
	i = 0;
	while (i < pipex.size)
	{
		pid = fork();
		if (pid == 0)
		{
			if (i == pipex.size - 1)
				last_child(pipex, i);
			else
				child(pipex, i);
		}
	}
	waitpid(pid, NULL, 0);
	return (true);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc < 5)
		return (EXIT_FAILURE);
	pipex.size = argc - 3;
	if (!parse_input(&pipex, argv, envp))
		return (free_pipex(&pipex));
	if (!piping(pipex))
		return (free_pipex(&pipex), EXIT_FAILURE);
	print_pipex(pipex);
	free_pipex(&pipex);
	return (EXIT_SUCCESS);
}

//add envp to pipex!
