/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:55:44 by jkoupy            #+#    #+#             */
/*   Updated: 2023/12/21 21:15:05 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

//close all the pipes created, free pipes, and free the pipe array
//also close infile and outfile
bool	close_all_fds(t_pipex *pipex)
{
	int	i;

	i = 0;
	if (!pipex->pipes)
		return (false);
	while (i < pipex->size && pipex->pipes[i])
	{
		close(pipex->pipes[i][0]);
		close(pipex->pipes[i][1]);
		if (pipex->pipes[i])
			free(pipex->pipes[i]);
		i++;
	}
	free(pipex->pipes);
	if (pipex->infile != -1)
		close(pipex->infile);
	if (pipex->outfile != -1)
		close(pipex->outfile);
	return (true);
}

//free allocated pipex elements, all cmds, paths
//close infile and outfile, unlink .here_doc
bool	free_pipex(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->size && pipex->cmds && pipex->cmds[i].args)
	{
		free_array(pipex->cmds[i].args);
		if (pipex->cmds[i].found)
			free(pipex->cmds[i].path);
		i++;
	}
	free(pipex->cmds);
	if (pipex->paths)
		free_array(pipex->paths);
	if (pipex->infile != -1)
		close(pipex->infile);
	if (pipex->outfile != -1)
		close(pipex->outfile);
	if (pipex->child_pids)
		free(pipex->child_pids);
	if (pipex->heredoc)
		unlink(".here_doc");
	return (true);
}

//free all elements of an array of strings including the array itself
//needs to be NULL terminated
bool	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (false);
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (true);
}
