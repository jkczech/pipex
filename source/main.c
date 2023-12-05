/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:26:55 by jkoupy            #+#    #+#             */
/*   Updated: 2023/12/05 15:24:21 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

//create all pipes needed
//pipex.pipes is not NULL terminated
bool	create_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	pipex->pipes = malloc((pipex->size) * sizeof(int *));
	if (!pipex->pipes)
		return (false);
	while (i < pipex->size)
	{
		pipex->pipes[i] = malloc(2 * sizeof(int));
		if (!pipex->pipes[i])
			return (false);
		if (pipe(pipex->pipes[i]) == -1)
			return (false);
		i++;
	}
	return (true);
}

//waiting for all the child processes to finish
bool	wait_pids(t_pipex pipex)
{
	int	i;

	i = 0;
	while (i < pipex.size && pipex.child_pids[i] > 0)
	{
		waitpid(pipex.child_pids[i], NULL, 0);
		i++;
	}
	return (true);
}

bool	allocate_pids(t_pipex *pipex)
{
	int	i;

	pipex->child_pids = malloc(pipex->size * sizeof(int));
	if (!pipex->child_pids)
		return (false);
	i = 0;
	while (i < pipex->size)
	{
		pipex->child_pids[i] = -1;
		i++;
	}
	return (true);
}

//fork, pipe, execute in child processes
bool	execute(t_pipex pipex)
{
	int	pid;
	int	i;

	if (!allocate_pids(&pipex))
		return (false);
	i = 0;
	while (i < pipex.size)
	{
		if (i == 0 && pipex.skip_first)
		{
			i++;
			continue ;
		}
		pid = fork();
		if (pid == 0)
			child(pipex, i);
		else if (pid > 0)
			pipex.child_pids[i] = pid;
		else
			return (close_pipes(&pipex), free(pipex.child_pids), false);
		i++;
	}
	close_pipes(&pipex);
	return (wait_pids(pipex), free(pipex.child_pids), true);
}

void	pipex_init(t_pipex *pipex)
{
	pipex->size = 0;
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc < 5)
	{
		ft_putstr_fd("Error: Not enough arguments\n", 2);
		return (EXIT_FAILURE);
	}
	pipex.size = argc - 3;
	pipex_init(&pipex);
	if (!parse_input(&pipex, argv, envp))
		return (free_pipex(&pipex), EXIT_FAILURE);
	pipex.child_pids = NULL;
	create_pipes(&pipex);
	if (!execute(pipex))
		return (free_pipex(&pipex), error_message(), EXIT_FAILURE);
	free_pipex(&pipex);
	return (EXIT_SUCCESS);
}
