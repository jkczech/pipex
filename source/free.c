/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:55:44 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/28 15:04:00 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

bool	free_pipex(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->size && pipex->cmd && pipex->cmd[i].args)
	{
		free_array(pipex->cmd[i].args);
		i++;
	}
	if (pipex->paths)
		free_array(pipex->paths);
	free(pipex->cmd);
	close(pipex->infile);
	close(pipex->outfile);
	return (true);
}

bool	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array || !array[0])
		return (false);
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (true);
}
