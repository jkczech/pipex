/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:26:55 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/30 16:03:17 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

bool	create_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	pipex->pipes = malloc((pipex->size) * sizeof(int *));
	if (!pipex->pipes)
		return (false);
	pipex->pipes[pipex->size] = NULL;
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

bool	wait_pids(t_pipex pipex, int *child_pids)
{
	int i;

	i = 0;
	while (i < pipex.size && child_pids[i] > 0)
	{
		waitpid(child_pids[i], NULL, 0);
		i++;
	}
	return (true);
}

bool	execute(t_pipex pipex)
{
	int	pid;
	int	i;
	int *child_pids;

	i = 0;
	child_pids = malloc(pipex.size * sizeof(int));
	if (!child_pids)
		return (false);
	for (int j = 0; j < pipex.size; j++)
        child_pids[j] = -1;
	while (i < pipex.size)
	{
		pid = fork();
		if (pid == 0)
		{
			if (i == 0)
				first_child(pipex, i);
			else if (i != pipex.size - 1)
				middle_child(pipex, i);
			else
				last_child(pipex, i);
		}
		else if (pid > 0)
			child_pids[i] = pid;
		else
			return (free(child_pids), false);
		i++;
	}
	wait_pids(pipex, child_pids);
	return (free(child_pids), true);
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
	if (!parse_input(&pipex, argv, envp))
		return (free_pipex(&pipex), error_message(), EXIT_FAILURE);
	create_pipes(&pipex);
	if (!execute(pipex))
		return (free_pipex(&pipex), error_message(), EXIT_FAILURE);
	//print_pipex(pipex);
	free_pipex(&pipex);
	return (EXIT_SUCCESS);
}
