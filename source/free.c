/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:55:44 by jkoupy            #+#    #+#             */
/*   Updated: 2023/12/05 09:26:48 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

//closes all the pipes created, frees pipes, and frees the pipe array
bool	close_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->size && pipex->pipes[i])
	{
		//if (pipex->pipes[i][0] != -1)
		close(pipex->pipes[i][0]);
		//if (pipex->pipes[i][1] != -1)
		close(pipex->pipes[i][1]);
		free(pipex->pipes[i]);
		i++;
	}
	free(pipex->pipes);
	return (true);
}

//frees pipex elements that are allocated, all cmd's, paths
//closes infile and outfile
bool	free_pipex(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->size && pipex->cmds && pipex->cmds[i].args)
	{
		free_array(pipex->cmds[i].args);
		free(pipex->cmds[i].path);
		i++;
	}
	if (pipex->paths)
		free_array(pipex->paths);
	free(pipex->cmds);
	//close_pipes(pipex);
	if (pipex->infile != -1)
		close(pipex->infile);
	printf("%d", pipex->outfile);
	close(pipex->outfile);
	return (true);
}

//frees all elements of an array of strings including the array itself
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
