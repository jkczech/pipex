/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:55:44 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/29 15:09:03 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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
	close(pipex->infile);
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
