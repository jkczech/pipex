/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:34:49 by jkoupy            #+#    #+#             */
/*   Updated: 2023/12/22 21:12:49 by jkoupy           ###   ########.fr       */
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
bool	wait_pids(t_pipex *pipex)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (i < pipex->size && pipex->child_pids[i] > 0)
	{
		waitpid(pipex->child_pids[i], &status, 0);
		i++;
	}
	if (WIFEXITED(status))
		pipex->exitcode = WEXITSTATUS(status);
	return (true);
}

//allocate array of ints for the pids of child processes
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
bool	execute(t_pipex *pipex)
{
	int	pid;
	int	i;

	if (!allocate_pids(pipex))
		return (false);
	i = 0;
	while (i < pipex->size)
	{
		pid = fork();
		if (pid == 0)
			children(*pipex, i);
		else if (pid > 0)
			pipex->child_pids[i] = pid;
		else
			return (close_all_fds(pipex), false);
		i++;
	}
	close_all_fds(pipex);
	wait_pids(pipex);
	return (true);
}
