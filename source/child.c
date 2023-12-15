/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:41:26 by jkoupy            #+#    #+#             */
/*   Updated: 2023/12/15 14:49:50 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

//redirecting left to stdin and right to stdout
//while closing left and right
void	redirect(t_pipex pipex, int input, int output)
{
	if (dup2(input, STDIN_FILENO) == -1)
	{
		close_pipes(&pipex);
		free_pipex(&pipex);
		exit(1);
	}
	close(input);
	if (dup2(output, STDOUT_FILENO) == -1)
	{
		close_pipes(&pipex);
		free_pipex(&pipex);
		exit(1);
	}
	close(output);
}

//handling different kinds of child processes, first, middle, last
void	children(t_pipex pipex, int i)
{
	if (!pipex.cmds[i].found)
	{
		close_pipes(&pipex);
		free_pipex(&pipex);
		exit(1);
	}
	if (i == 0)
		child(pipex, i, pipex.infile, pipex.pipes[i][1]);
	else if (i != pipex.size - 1)
		child(pipex, i, pipex.pipes[i - 1][0], pipex.pipes[i][1]);
	else
		child(pipex, i, pipex.pipes[i - 1][0], pipex.outfile);
	exit(1);
}

//handling first child process, connects to infile
void	child(t_pipex pipex, int i, int input, int output)
{
	redirect(pipex, input, output);
	close_pipes(&pipex);
	if (execve(pipex.cmds[i].path, pipex.cmds[i].args, pipex.envp) == -1)
	{
		free_pipex(&pipex);
		error_message(NULL);
	}
	exit(1);
}
