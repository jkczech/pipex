/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:34:49 by jkoupy            #+#    #+#             */
/*   Updated: 2023/12/06 13:41:19 by jkoupy           ###   ########.fr       */
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
int wait_pids(t_pipex pipex)
{
	int	i;
    int status;

	i = 0;
	while (i < pipex.size && pipex.child_pids[i] > 0)
	{
		waitpid(pipex.child_pids[i], &status, 0);
		i++;
	}
	return (status);
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
int execute(t_pipex pipex)
{
	int	pid;
	int	i;

	if (!allocate_pids(&pipex))
		return (0);
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
			return (close_pipes(&pipex), free(pipex.child_pids), 0);
		i++;
	}
	close_pipes(&pipex);
	return (wait_pids(pipex), free(pipex.child_pids), 1);
}

void	pipex_init(t_pipex *pipex)
{
	pipex->size = 0;
	pipex->skip_first = false;
	pipex->paths = NULL;
}
