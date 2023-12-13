/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:41:26 by jkoupy            #+#    #+#             */
/*   Updated: 2023/12/13 12:15:40 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

//redirecting left to stdin and right to stdout
//while closing left and right
void	redirect(int input, int output)
{
	if (dup2(input, STDIN_FILENO) == -1)
		exit(1);
	close(input);
	if (dup2(output, STDOUT_FILENO) == -1)
		exit(1);
	close(output);
}

//handling different kinds of child processes
bool	child(t_pipex pipex, int i)
{
	if (!pipex.cmds[i].found)
	{
		close_pipes(&pipex);
		free_pipex(&pipex);
		exit(1);
	}
	if (i == 0)
		first_child(pipex, i);
	else if (i != pipex.size - 1)
		middle_child(pipex, i);
	else
		last_child(pipex, i);
	exit(1);
}

//handling first child process, connects to infile
bool	first_child(t_pipex pipex, int i)
{
	redirect(pipex.infile, pipex.pipes[i][1]);
	close_pipes(&pipex);
	execve(pipex.cmds[i].path, pipex.cmds[i].args, pipex.envp);
	return (true);
}

//handling middle child processes connecting the previous pipe
bool	middle_child(t_pipex pipex, int i)
{
	redirect(pipex.pipes[i - 1][0], pipex.pipes[i][1]);
	close_pipes(&pipex);
	execve(pipex.cmds[i].path, pipex.cmds[i].args, pipex.envp);
	return (true);
}

//handling last child process, connects to outfile
bool	last_child(t_pipex pipex, int i)
{
	redirect(pipex.pipes[i - 1][0], pipex.outfile);
	close_pipes(&pipex);
	execve(pipex.cmds[i].path, pipex.cmds[i].args, pipex.envp);
	return (true);
}
